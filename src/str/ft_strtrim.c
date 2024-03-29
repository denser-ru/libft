/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:01:51 by cayako            #+#    #+#             */
/*   Updated: 2021/11/14 13:59:39 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	b;
	size_t	e;
	size_t	l;

	if (!s)
		return (NULL);
	b = 0;
	while (s[b] != '\0' && (s[b] == ' ' || s[b] == '\n' || s[b] == '\t'))
		b++;
	e = ft_strlen(s);
	while (b < e && (s[e - 1] == ' '
			|| s[e - 1] == '\n' || s[e - 1] == '\t'))
		e--;
	if (b == e)
		return (ft_strnew(0));
	l = e - b;
	return (ft_strsub(s, b, l));
}
