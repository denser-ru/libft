/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 21:06:32 by cayako            #+#    #+#             */
/*   Updated: 2021/11/14 13:59:39 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpushb(t_list **root, void *content, size_t content_size)
{
	t_list	*new;
	t_list	*cur;

	cur = *root;
	if (*root == NULL)
		*root = ft_lstnew(content, content_size);
	else
	{
		new = ft_lstnew(content, content_size);
		if (!new)
			return (NULL);
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	}
	return (*root);
}
