/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denser <denser@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:19:44 by denser            #+#    #+#             */
/*   Updated: 2021/10/27 14:19:44 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_map.h"

t_map	*ft_map_new(void)
{
	t_map	*map;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->end = map->mem;
	map->tail = map->arr;
	map->last = map->arr;
	map->root = map->arr;
	return (map);
}
