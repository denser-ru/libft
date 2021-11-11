/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:58:04 by cayako            #+#    #+#             */
/*   Updated: 2021/10/27 12:56:08 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_abs(long long n)
{
	if (n < 0)
		n = -n;
	return (n);
}

long double	ft_abs_ld(long double n)
{
	if (n < 0)
		n = -n;
	return (n);
}