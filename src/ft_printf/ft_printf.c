/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clashund <clashund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:09:40 by clashund          #+#    #+#             */
/*   Updated: 2021/04/12 19:01:54 by clashund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_convs	*init_convs(void)
{
	t_convs	*p_convs;

	p_convs = (t_convs *)malloc(sizeof(t_convs));
	p_convs->sharp = 0;
	p_convs->zero = 0;
	p_convs->minus = 0;
	p_convs->space = 0;
	p_convs->plus = 0;
	p_convs->width = 0;
	p_convs->precision = -1;
	p_convs->length = 0;
	p_convs->conversion = 0;
	return (p_convs);
}

size_t	lets_solut(t_convs *p_convs, va_list *ap, int func)
{
	size_t	(*funcs[4])(t_convs *, va_list *);

	funcs[0] = &letsprint_csp;
	funcs[1] = &letsprint_dioux;
	funcs[2] = &letsprint_f;
	funcs[3] = &letsprint_percent;
	return ((*funcs[func])(p_convs, ap));
}

size_t	letsprint(t_convs *p_convs, va_list *ap)
{
	size_t	res;
	int		func;

	func = 0;
	if (ft_strchr("csp", p_convs->conversion))
		func = 0;
	else if (ft_strchr("diouxX", p_convs->conversion))
		func = 1;
	else if (ft_strchr("f", p_convs->conversion))
		func = 2;
	else if (p_convs->conversion == '%')
		func = 3;
	res = lets_solut(p_convs, ap, func);
	return (res);
}

size_t	letspars(const char *fmt, size_t i, va_list *ap, size_t *res)
{
	t_convs	*p_convs;

	if (fmt[i] == '\0')
		return (0);
	p_convs = init_convs();
	if (is_flag(fmt[i]))
		i = letspars_flags(fmt, i, p_convs);
	if (!i)
		return (0);
	if (ft_isdigit(fmt[i]) || fmt[i] == '*')
		i = letspars_width(fmt, i, p_convs, ap);
	if (fmt[i] == '.')
	{
		p_convs->precision = 0;
		i = letspars_precision(fmt, ++i, p_convs, ap);
	}
	if (is_length(fmt[i]))
		i = letspars_length(fmt, i, p_convs);
	if (is_conversion(fmt[i]))
		i = letspars_conversion(fmt, i, p_convs);
	*res = *res + letsprint(p_convs, ap);
	free(p_convs);
	return (i);
}

int	ft_printf(const char *fmt, ...)
{
	size_t	res;
	size_t	i;
	va_list	ap;
	size_t	len_fmt;

	res = 0;
	i = 0;
	len_fmt = ft_strlen(fmt);
	va_start(ap, fmt);
	while (i < len_fmt && fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			i = letspars(fmt, ++i, &ap, &res);
			if (!i)
				return (res);
		}
		else
		{
			write(1, &(fmt[i++]), 1);
			++res;
		}
	}
	va_end(ap);
	return (res);
}
