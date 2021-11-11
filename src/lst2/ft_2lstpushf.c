/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2lstpushf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:51:20 by cayako            #+#    #+#             */
/*   Updated: 2021/11/09 14:57:59 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_2list	*ft_2lstpushf(t_2list **root, void *content, size_t content_size)
{
	t_2list	*new;

	if (*root == NULL)
		*root = ft_2lstnew(content, content_size);
	else
	{
		new = ft_2lstnew(content, content_size);
		if (!new)
			return (NULL);
		new->next = *root;
		(*root)->prev = new;
		*root = new;
	}
	return (*root);
}
