/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_del_elm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:20:05 by cayako            #+#    #+#             */
/*   Updated: 2021/10/28 18:55:38 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_map.h"

int	ft_map_del_elm(t_map *map, char *key)
{
	t_map_elm	*elm;

	elm = ft_map_get_elm(map, key);
	if (!elm)
		return (1);
	if (elm == map->root && elm->next)
		map->root = elm->next;
	else if (elm == map->root)
		map->root = map->arr;
	if (elm == map->tail && elm->prev)
		map->tail = elm->prev;
	else if (elm == map->tail)
		map->tail = map->arr;
	if (elm->prev)
		elm->prev->next = elm->next;
	if (elm->next)
		elm->next->prev = elm->prev;
	if (map->count)
		--map->count;
	++map->deleted;
	return (0);
}
