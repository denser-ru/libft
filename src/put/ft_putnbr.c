/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 01:53:49 by cayako            #+#    #+#             */
/*   Updated: 2021/11/14 13:59:39 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	char	s[13];
	int		i;
	long	ln;

	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	i = 11;
	ft_bzero(s, 13);
	if (n < 0)
		ln = -(long)n;
	else
		ln = n;
	while (ln > 0)
	{
		s[i] = '0' + ln % 10;
		ln /= 10;
		--i;
	}
	if (n < 0)
		s[i--] = '-';
	ft_putstr(&s[i + 1]);
}
