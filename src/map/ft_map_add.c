/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:20:20 by cayako            #+#    #+#             */
/*   Updated: 2021/11/08 18:18:23 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_map.h"

static t_map_elm	*new_key(t_map *map, char *key, char *value,
						t_map_elm *elm);
static t_map_elm	*find_current_location(t_map_elm *elm, char *key);
static void			insert_elm(t_map *map, t_map_elm *cur, t_map_elm *in);

t_map	*ft_map_add(t_map *map, char *key, char *value)
{
	t_map_elm	*cur;
	t_map_elm	*in;

	if (map->size + ft_strlen(key) + ft_strlen(value) + 2 >= FT_MAP_BUF
		|| map->count + map->deleted + 1 >= FT_MAP_MAX_ELM)
	{
		ft_strncpy(map->err, "memory MAP is full", FT_ERR_LEN);
		return (NULL);
	}
	cur = map->last;
	in = find_current_location(map->root, key);
	new_key(map, key, value, map->last);
	++map->count;
	map->size += map->last->size_key + map->last->size_value + 2;
	map->end += map->last->size_key + map->last->size_value + 2;
	map->last++;
	if (!in)
	{
		cur->prev = map->tail;
		map->tail->next = cur;
		map->tail = cur;
	}
	else
		insert_elm(map, cur, in);
	return (map);
}

inline static void	insert_elm(t_map *map, t_map_elm *cur, t_map_elm *in)
{
	if (in->prev)
		in->prev->next = cur;
	else
		map->root = cur;
	if (cur != in)
	{
		cur->prev = in->prev;
		cur->next = in;
		in->prev = cur;
	}
}

static t_map_elm	*find_current_location(t_map_elm *elm, char *key)
{
	char	*cur;

	cur = elm->key;
	while (cur && ft_strcmp(cur, key) <= 0)
	{
		elm = elm->next;
		if (!elm)
			return (NULL);
		cur = elm->key;
	}
	return (elm);
}

static t_map_elm	*new_key(t_map *map, char *key, char *value, t_map_elm *elm)
{
	elm->size_key = ft_strlen(key);
	elm->size_value = ft_strlen(value);
	elm->key = map->end;
	elm->value = map->end + elm->size_key + 1;
	ft_memcpy(elm->key, key, elm->size_key);
	ft_memcpy(elm->value, value, elm->size_value);
	return (elm);
}
