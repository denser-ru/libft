/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2lstcut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 01:03:07 by cayako            #+#    #+#             */
/*   Updated: 2021/11/14 13:59:39 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_2lstcut(t_2list **root, t_2list *cut, void (*del)(void *, size_t))
{
	if (!cut)
		return ;
	if (cut == *root)
	{
		*root = cut->next;
		if (*root)
			(*root)->prev = NULL;
		ft_2lstdelone(&cut, del);
	}
	else
	{
		if (cut->next)
			cut->next->prev = cut->prev;
		cut->prev->next = cut->next;
		ft_2lstdelone(&cut, del);
	}
}
