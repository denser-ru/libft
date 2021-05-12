/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clashund <clashund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:05:48 by smanta            #+#    #+#             */
/*   Updated: 2021/04/10 22:27:58 by clashund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_char_n(char c, int num)
{
	size_t	len;

	len = 0;
	if (num >= 0)
	{
		len = num;
		while (num--)
			write(1, &c, 1);
	}
	return (len);
}

static long long	get_ll_with_length(t_convs *p_convs, int ival)
{
	long long	res;

	res = ival;
	if (p_convs->length == 0)
	{
		if (p_convs->conversion == 'u')
			res = (unsigned int)res;
	}
	else if (p_convs->length == 1)
	{
		if (p_convs->conversion == 'u')
			res = (unsigned short)res;
		else
			res = (short)res;
	}
	else if (p_convs->length == 4)
	{
		if (p_convs->conversion == 'u')
			res = (unsigned char)res;
		else
			res = (char)res;
	}
	return (res);
}

long long	get_arg(t_convs *p_convs, va_list *ap)
{
	int			ival;
	long long	llval;

	llval = 0;
	if (p_convs->length == 0 || p_convs->length == 1 || p_convs->length == 4)
	{
		ival = va_arg(*ap, int);
		llval = get_ll_with_length(p_convs, ival);
	}
	else if (p_convs->length == 2)
		llval = va_arg(*ap, long);
	else if (p_convs->length == 5)
		llval = va_arg(*ap, long long);
	return (llval);
}

static unsigned long long	get_ull_with_length(t_convs *p_convs,
												unsigned int ival)
{
	unsigned long long	res;

	res = ival;
	if (p_convs->length == 1)
		res = (unsigned short)res;
	else if (p_convs->length == 4)
		res = (unsigned char)res;
	return (res);
}

unsigned long long	get_uarg(t_convs *p_convs, va_list *ap)
{
	unsigned int		ival;
	unsigned long long	llval;

	llval = 0;
	if (p_convs->length == 0 || p_convs->length == 1 || p_convs->length == 4)
	{
		ival = va_arg(*ap, int);
		llval = get_ull_with_length(p_convs, ival);
	}
	else if (p_convs->length == 2)
		llval = va_arg(*ap, long);
	else if (p_convs->length == 5)
		llval = va_arg(*ap, long long);
	return (llval);
}
