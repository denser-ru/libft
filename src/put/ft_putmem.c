/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 03:03:40 by cayako            #+#    #+#             */
/*   Updated: 2019/10/26 01:38:29 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_mem(t_putmem *out, char const *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	if (!out->p)
		p = out->mem;
	if (out->p - out->mem + len >= FT_PUTMEM)
		return (-1);
	ft_memcpy(out->p, s, len);
	out->count += len;
	p += len;
	return (len)
}

int	ft_putnstr_mem(t_putmem *out, char const *s, size_t n)
{
	if (!s)
		return (0);
	if (!out->p)
		p = out->mem;
	if (out->p - out->mem + len >= FT_PUTMEM)
		return (-1);
	ft_memcpy(out->p, s, n);
	out->count += n;
	p += n;
	return (len)
}
