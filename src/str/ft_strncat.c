/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:24:10 by cayako            #+#    #+#             */
/*   Updated: 2019/10/26 01:38:29 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	l;
	size_t	i;

	l = ft_strlen(s1);
	i = 0;
	while (s2[i] && i < n)
	{
		*(s1 + l + i) = *(s2 + i);
		i++;
	}
	*(s1 + l + i) = '\0';
	return (s1);
}
