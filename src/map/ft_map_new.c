/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:19:44 by cayako            #+#    #+#             */
/*   Updated: 2021/10/28 18:56:00 by cayako           ###   ########.fr       */
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
