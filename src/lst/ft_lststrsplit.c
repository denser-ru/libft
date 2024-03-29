/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 20:49:43 by cayako            #+#    #+#             */
/*   Updated: 2021/11/14 13:59:39 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lststrsplit(char const *s, char c)
{
	t_list		*root;
	char		*e;

	root = NULL;
	if (!(s))
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			++s;
		e = ft_strchr(s, c);
		if (!e)
			e = (char *)(s + ft_strlen(s));
		if (e != s)
			ft_lstpushb(&root, (void *)s, e - s);
		s = e;
	}
	return (root);
}
