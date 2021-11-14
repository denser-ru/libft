/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:47:17 by cayako            #+#    #+#             */
/*   Updated: 2021/11/14 13:59:39 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_map.h"

t_map_elm	*ft_map_set(t_map *map, char *key, char *value)
{
	t_map_elm	*elm;

	elm = ft_map_get_elm(map, key);
	if (!elm)
		return (ft_map_add(map, key, value));
	return (ft_map_set_content(map, &elm, key, value));
}

t_map_elm	*ft_map_set_content(t_map *map, t_map_elm **elm, char *key,
				char *value)
{
	ft_map_set_key(map, elm, key);
	ft_map_set_value(map, elm, value);
	return (*elm);
}

t_map_elm	*ft_map_set_key(t_map *map, t_map_elm **elm, char *key)
{
	(*elm)->b_key.content_size = ft_strlen(key);
	if ((*elm)->key && (*elm)->key->content_size > FT_MAP_MAX_NAME_LEN)
		ft_2lstcut(&map->big_value, (*elm)->key, ft_lstdelcontent);
	if ((*elm)->b_key.content_size <= FT_MAP_MAX_NAME_LEN)
	{
		(*elm)->key = &(*elm)->b_key;
		(*elm)->key->content = (*elm)->s_key;
		(*elm)->key->content_size = (*elm)->b_key.content_size;
		ft_strcpy((*elm)->key->content, key);
	}
	else
	{
		(*elm)->key = ft_2lstpushf(&map->big_value, key,
			(*elm)->b_key.content_size);
		if (!(*elm)->key)
		{
			ft_strncpy(map->err, "can`t get memory for ft_2lstnew()",
					   FT_ERR_LEN);
			return (NULL);
		}
	}
	return (*elm);
}

t_map_elm	*ft_map_set_value(t_map *map, t_map_elm **elm, char *value)
{
	(*elm)->b_value.content_size = ft_strlen(value);
	if ((*elm)->value && (*elm)->value->content_size > FT_MAP_MAX_NAME_LEN)
		ft_2lstcut(&map->big_value, (*elm)->value, ft_lstdelcontent);
	if ((*elm)->b_value.content_size <= FT_MAP_MAX_NAME_LEN)
	{
		(*elm)->value = &(*elm)->b_value;
		(*elm)->value->content = (*elm)->s_value;
		(*elm)->value->content_size = (*elm)->b_value.content_size;
		ft_strcpy((*elm)->value->content, value);
	}
	else
	{
		(*elm)->value = ft_2lstpushf(&map->big_value, value,
									 (*elm)->b_value.content_size);
		if (!(*elm)->value)
		{
			ft_strncpy(map->err, "can`t get memory for ft_2lstnew()",
					   FT_ERR_LEN);
			return (NULL);
		}
	}
	return (*elm);
}
