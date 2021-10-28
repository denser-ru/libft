/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:24:59 by cayako            #+#    #+#             */
/*   Updated: 2021/10/28 18:55:38 by cayako           ###   ########.fr       */
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
