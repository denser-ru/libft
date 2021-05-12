/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ox.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clashund <clashund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:16:00 by clashund          #+#    #+#             */
/*   Updated: 2021/04/10 19:52:54 by clashund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	handle_spaces(t_convs *p_convs,
		const char *str, int num_len, int sign_arg)
{
	size_t	res;
	int		s;
	int		o;

	res = 0;
	s = comp_out((p_convs->plus == 1 && sign_arg == 1)
			|| sign_arg == 0 || (p_convs->space == 1 && sign_arg == 1), -1, 0);
	o = comp_out(p_convs->sharp && p_convs->conversion == 'o'
			&& *str != '0', -1, 0);
	if (p_convs->sharp == 1 && (p_convs->conversion == 'x'
			|| p_convs->conversion == 'X') && *str != '0')
		s -= 2;
	s = comp_out(num_len >= p_convs->precision, s + o + p_convs->width
			- num_len, s + p_convs->width - p_convs->precision);
	if (p_convs->precision == 0 && *str == '0'
		&& !(p_convs->sharp == 1 && p_convs->conversion == 'o' && *str == '0'))
		++s;
	if (p_convs->zero == 1)
		s = 0;
	res += print_char_n(' ', s);
	return (res);
}

static size_t	preprint_data(t_convs *p_c, char *str, int num_len, char c)
{
	size_t	res;
	int		oxx;

	res = 0;
	oxx = 0;
	if (p_c->sharp == 1 && *str != '0' && p_c->conversion == 'o')
	{
		oxx = print_char_n('0', 1);
		++res;
	}
	if (p_c->sharp == 1 && *str != '0'
		&& (p_c->conversion == 'x' || p_c->conversion == 'X'))
	{
		ft_compare_out_x(p_c->conversion == 'x', 1, "", "");
		res += 2;
		oxx += 2;
	}
	if (p_c->zero == 1 && p_c->precision == -1)
	{
		num_len = comp_out(c != '\0', num_len + 1, num_len);
		res += print_char_n('0', p_c->width - num_len - oxx);
	}
	oxx = comp_out(p_c->conversion == 'x' || p_c->conversion == 'X', 0, oxx);
	return (comp_out(num_len < p_c->precision, res
			+ print_char_n('0', p_c->precision - num_len - oxx), res));
}

static size_t	handle_value(t_convs *p_convs,
		char *str, int num_len, int sign_arg)
{
	size_t	res;
	char	c;
	char	*temp_str;

	res = 0;
	c = comp_out(p_convs->plus == 1 && sign_arg == 1, '+', '\0');
	c = comp_out(sign_arg == 0, '-', '\0');
	c = comp_out(p_convs->space == 1 && sign_arg == 1, ' ', '\0');
	if (c)
		res += print_char_n(c, 1);
	res += preprint_data(p_convs, str, num_len, c);
	if (p_convs->precision != 0
		|| (p_convs->precision == 0 && (num_len > 0 && *str != '0'))
		|| (p_convs->sharp == 1 && p_convs->conversion == 'o' && *str == '0'))
	{
		res += num_len;
		temp_str = ft_strmap(str, (char (*)(char)) ft_tolower);
		ft_compare_out_x(p_convs->conversion == 'X', 0, str, temp_str);
		free(temp_str);
	}
	return (res);
}

static char	*print_oxut(int comp, unsigned long long llval)
{
	if (comp)
		return (ft_ulltoa_base(llval, 8));
	else
		return (ft_ulltoa_base(llval, 16));
}

size_t	print_ox(t_convs *p_convs, va_list *ap)
{
	size_t				res;
	unsigned long long	llval;
	char				*str;
	int					num_len;

	llval = get_uarg(p_convs, ap);
	str = print_oxut(p_convs->conversion == 'o', llval);
	num_len = ft_strlen(str);
	if (p_convs->zero == 1 && (p_convs->precision != -1 || p_convs->minus == 1))
		p_convs->zero = 0;
	if (p_convs->plus == 1 && p_convs->space == 1)
		p_convs->space = 0;
	if (p_convs->minus == 0)
	{
		res = handle_spaces(p_convs, str, num_len, 1);
		res += handle_value(p_convs, str, num_len, 1);
	}
	else
	{
		res = handle_value(p_convs, str, num_len, 1);
		res += handle_spaces(p_convs, str, num_len, 1);
	}
	free(str);
	return (res);
}
