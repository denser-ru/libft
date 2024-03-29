/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrtoarr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 00:00:10 by cayako            #+#    #+#             */
/*   Updated: 2021/11/14 13:59:39 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_lststrtoarr(t_list *lststr)
{
	char	**arr;
	char	**cur;

	arr = (char **)malloc(sizeof(char *) * (ft_lstsize(lststr) + 1));
	if (!arr)
		return (NULL);
	cur = arr;
	while (lststr)
	{
		*cur = ft_memalloc(lststr->content_size + 1);
		if (!(*cur))
			return (NULL);
		ft_memcpy(*cur, lststr->content, lststr->content_size);
		++cur;
		lststr = lststr->next;
	}
	*cur = NULL;
	return (arr);
}
