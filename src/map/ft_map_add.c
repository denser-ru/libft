/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:20:20 by cayako            #+#    #+#             */
/*   Updated: 2021/11/14 13:59:39 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_map.h"

static t_map_elm	*new_key(t_map *map, char *key, char *value,
						t_map_elm **elm);
static t_map_elm	*elm_restore(t_map *map, t_map_elm *elm);

t_map_elm	*ft_map_add(t_map *map, char *key, char *value)
{
	t_map_elm	*cur;
	t_map_elm	*in;

	if (map->count >= FT_MAP_MAX_ELM)
	{
		ft_strncpy(map->err, "memory MAP is full", FT_ERR_LEN);
		return (NULL);
	}
	cur = map->last;
	in = find_current_location(map->root, key);
	new_key(map, key, value, &cur);
	if (!in && cur != map->root)
	{
		cur->prev = map->tail;
		map->tail->next = cur;
		map->tail = cur;
	}
	else if (in)
		insert_elm(map, cur, in);
	return (cur);
}

void	insert_elm(t_map *map, t_map_elm *cur, t_map_elm *in)
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

t_map_elm	*find_current_location(t_map_elm *elm, char *key)
{
	char	*cur;

	if (!elm->key)
		return (NULL);
	cur = (char *)elm->key->content;
	while (cur && ft_strcmp(cur, key) <= 0)
	{
		elm = elm->next;
		if (!elm)
			return (NULL);
		cur = (char *)elm->key->content;
	}
	return (elm);
}

static t_map_elm	*new_key(t_map *map, char *key, char *value,
						t_map_elm **elm)
{
	char	del;

	del = (char)(map->deleted > 0);
	if (del)
		*elm = elm_restore(map, *elm);
	ft_map_set_content(map, elm, key, value);
	++map->count;
	map->size += (*elm)->key->content_size + (*elm)->value->content_size;
	if (!del)
		map->last++;
	return (*elm);
}

static t_map_elm	*elm_restore(t_map *map, t_map_elm *elm)
{
	if (!map->del_list)
		return (NULL);
	elm = (t_map_elm *)(map->del_list->content);
	if (map->del_list->next)
		map->del_list = map->del_list->next;
	if (map->del_list->prev)
	{
		free(map->del_list->prev);
		map->del_list->prev = NULL;
	}
	--map->deleted;
	return (elm);
}
