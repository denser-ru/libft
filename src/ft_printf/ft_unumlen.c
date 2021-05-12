/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unumlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clashund <clashund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 20:16:07 by smanta            #+#    #+#             */
/*   Updated: 2021/04/09 20:06:36 by clashund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unumlen(unsigned long long num)
{
	int	len;

	len = 1;
	while (num / 10 > 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}
