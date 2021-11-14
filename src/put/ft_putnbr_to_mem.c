/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_to_mem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 01:53:49 by cayako            #+#    #+#             */
/*   Updated: 2021/11/14 13:59:39 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_to_mem(char *out, int n)
{
	char	s[13];
	int		i;
	long	ln;

	if (n == 0)
	{
		*out = '0';
		return (1);
	}
	i = 11;
	s[12] = '\0';
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
	ft_memcpy(out, &s[i + 1], 12 - i);
	return (11 - i);
}
