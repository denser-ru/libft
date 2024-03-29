/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 14:40:31 by cayako            #+#    #+#             */
/*   Updated: 2021/11/14 13:59:39 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*flst;
	t_list	*t1;
	t_list	*t2;

	if (!lst || !f)
		return (NULL);
	t2 = f(lst);
	flst = ft_lstnew(t2->content, t2->content_size);
	if (flst)
	{
		t1 = flst;
		lst = lst->next;
		while (lst)
		{
			t2 = f(lst);
			t1->next = ft_lstnew(t2->content, t2->content_size);
			if (!t1->next)
				return (NULL);
			t1 = t1->next;
			lst = lst->next;
		}
	}
	return (flst);
}
