/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_del_elm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:20:05 by cayako            #+#    #+#             */
/*   Updated: 2021/11/11 12:24:21 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_map.h"

static void	clean_elm(t_map *map, t_map_elm *elm);
static int	add_to_del_list(t_2list **root, void *content, size_t content_size);

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
	clean_elm(map, elm);
	++map->deleted;
	return (0);
}

static void	clean_elm(t_map *map, t_map_elm *elm)
{
	map->size -= elm->key->content_size + elm->key->content_size;
	if (elm->key->content_size > FT_MAP_MAX_NAME_LEN)
		ft_2lstcut(&map->big_value, elm->key->content, ft_lstdelcontent);
	if (elm->value->content_size > FT_MAP_MAX_NAME_LEN)
		ft_2lstcut(&map->big_value, elm->value->content, ft_lstdelcontent);
	ft_bzero(elm, sizeof(*elm));
	add_to_del_list(&map->del_list, elm, sizeof(*elm));
}

static int	add_to_del_list(t_2list **root, void *content, size_t content_size)
{
	t_2list	*new;

	new = ft_2lstnew(NULL, 0);
	new->content = content;
	new->content_size = content_size;
	if (!new)
		return (1);
	if (*root == NULL )
		*root = new;
	else
	{
		new->next = *root;
		(*root)->prev = new;
		*root = new;
	}
	return (0);
}