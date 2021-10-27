/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denser <denser@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:24:59 by denser            #+#    #+#             */
/*   Updated: 2021/10/27 16:24:59 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t len)
{
	char	*d;

	d = (char *)malloc(len + 1);
	if (!d)
		return (NULL);
	d[len] = '\0';
	while (len--)
		d[len] = s1[len];
	return (d);
}
