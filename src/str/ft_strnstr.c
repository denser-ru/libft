/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:47:42 by cayako            #+#    #+#             */
/*   Updated: 2019/10/26 01:38:29 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	l;
	char	*buf;

	buf = (char *)haystack;
	l = ft_strlen(needle);
	if (!l)
		return ((char *)haystack);
	haystack = ft_memchr(haystack, *needle, ft_strlen(haystack));
	while (haystack)
	{
		if (((haystack - buf) + l) > len)
			return (NULL);
		if (!ft_memcmp(haystack, needle, l))
			return ((char *)haystack);
		haystack++;
		haystack = ft_memchr(haystack, *needle, ft_strlen(haystack));
	}
	return (NULL);
}
