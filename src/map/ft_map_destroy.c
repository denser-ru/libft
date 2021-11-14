/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:15:56 by cayako            #+#    #+#             */
/*   Updated: 2021/11/14 13:59:39 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_map.h"

static void	free_del_list(t_2list **list);

int	ft_map_destroy(t_map **map)
{
	if (!*map)
		return (1);
	ft_2lstdel(&(*map)->big_value, ft_lstdelcontent);
	free_del_list(&(*map)->del_list);
	free(*map);
	*map = NULL;
	return (0);
}
static void	free_del_list(t_2list **list)
{
	if (*list)
	{
		free_del_list(&(*list)->next);
		free(*list);
		*list = NULL;
	}
}
