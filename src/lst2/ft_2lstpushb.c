/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2lstpushb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 21:06:32 by cayako            #+#    #+#             */
/*   Updated: 2021/11/09 14:35:03 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_2list	*ft_2lstpushb(t_2list **root, void *content, size_t content_size)
{
	t_2list	*new;
	t_2list	*cur;

	cur = *root;
	if (*root == NULL)
		*root = ft_2lstnew(content, content_size);
	else
	{
		new = ft_2lstnew(content, content_size);
		if (!new)
			return (NULL);
		while (cur->next)
			cur = cur->next;
		cur->next = new;
		new->prev = cur;
	}
	return (*root);
}
