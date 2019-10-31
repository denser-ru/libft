/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrtoarr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 00:00:10 by cayako            #+#    #+#             */
/*   Updated: 2019/11/01 00:23:55 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_lststrtoarr(t_list *lststr)
{
	char	**arr;

	if (!(arr = (char **)malloc(sizeof(char *) * ft_lstsize(lststr))))
		return (NULL);
	while (lststr)
	{
		if (!(*arr = ft_memalloc(lststr->content_size + 1)))
			return (NULL);
		ft_memcpy(*arr, lststr->content, lststr->content_size);
		++arr;
		lststr = lststr->next;
	}
	return (arr);
}
