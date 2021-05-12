/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clashund <clashund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:13:51 by clashund          #+#    #+#             */
/*   Updated: 2021/04/09 19:58:28 by clashund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen_base(unsigned long long num, int base)
{
	int	len;
	int	flag;

	len = num < 0;
	flag = (num /= base);
	while (flag)
	{
		len++;
		flag = (num /= base);
	}
	return (len + 1);
}

char	*ft_ulltoa_base(unsigned long long n, int b)
{
	char	*str_num;
	int		len;
	int		flag;

	len = ft_numlen_base(n, b);
	flag = (int)(str_num = ft_strnew(len));
	if (flag)
	{
		str_num[len] = '\0';
		while (len--)
		{
			if (b < 10)
				str_num[len] = n % b + '0';
			else
				str_num[len] = (n % b >= 10) * ((n % b) - 10 + 'A')
					+ !(n % b >= 10) * ((n % b) + '0');
			n /= b;
		}
	}
	return (str_num);
}
