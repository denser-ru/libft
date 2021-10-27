/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_del_elm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denser <denser@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:20:05 by denser            #+#    #+#             */
/*   Updated: 2021/10/27 14:20:05 by denser           ###   ########.fr       */
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
