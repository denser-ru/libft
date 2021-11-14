/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:28:04 by cayako            #+#    #+#             */
/*   Updated: 2021/11/14 13:59:39 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	l;

	l = ft_strlen(needle);
	if (!l)
		return ((char *)haystack);
	haystack = ft_memchr(haystack, *needle, ft_strlen(haystack));
	while (haystack)
	{
		if (!ft_memcmp(haystack, needle, l))
			return ((char *)haystack);
		haystack++;
		haystack = ft_memchr(haystack, *needle, ft_strlen(haystack));
	}
	return (NULL);
}
