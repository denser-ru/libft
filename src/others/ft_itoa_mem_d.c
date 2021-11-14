/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_mem_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 23:29:54 by cayako            #+#    #+#             */
/*   Updated: 2021/11/14 13:59:39 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_itoa_mem_d(void *dest, unsigned int nb)
{
	int		i;
	char	buf[12];

	i = 0;
	while (nb > 0)
	{
		buf[i++] = (char)(nb % 10 + '0');
		nb /= 10;
	}
	nb = i--;
	while (i >= 0)
	{
		*(char *)(dest + nb - i - 1) = (char)buf[i];
		--i;
	}
	return (nb);
}
