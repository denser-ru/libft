/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:56:56 by cayako            #+#    #+#             */
/*   Updated: 2021/11/14 13:59:39 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*buf;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	buf = (char *)malloc(ft_strlen(s) + 1);
	if (!buf)
		return (NULL);
	while (s[i++])
		buf[i - 1] = (*f)(i - 1, s[i - 1]);
	buf[i - 1] = '\0';
	return (buf);
}
