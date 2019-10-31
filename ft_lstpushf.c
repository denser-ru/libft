/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:51:20 by cayako            #+#    #+#             */
/*   Updated: 2019/10/31 19:51:40 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushf(t_list **root, void *content, size_t content_size)
{
	t_list *new;

	if (*root == NULL)
		*root = ft_lstnew(content, content_size);
	else
	{
		new = ft_lstnew(content, content_size);
		(*new).next = (*root);
		*root = new;
	}
}
