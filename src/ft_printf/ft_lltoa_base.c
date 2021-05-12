/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clashund <clashund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:09:11 by clashund          #+#    #+#             */
/*   Updated: 2021/04/09 15:51:47 by clashund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen_base(long long num, int base)
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

char	*ft_lltoa_base(long long n, int b)
{
	char				*str_num;
	int					len;
	unsigned long long	l;
	int					flag;

	len = ft_numlen_base(n, b);
	l = (n < 0) * -n + !(n < 0) * n;
	flag = (int)(str_num = ft_strnew(len));
	if (flag)
	{
		str_num[len] = '\0';
		while (len--)
		{
			if (b < 10)
				str_num[len] = l % b + '0';
			else
				str_num[len] = (l % b >= 10) * ((l % b) - 10 + 'A')
					+ !(l % b >= 10) * ((l % b) + '0');
			l /= b;
		}
		if (n < 0)
			str_num[0] = '-';
	}
	return (str_num);
}
