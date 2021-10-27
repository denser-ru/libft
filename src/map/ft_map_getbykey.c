/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_getbykey.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denser <denser@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:19:33 by denser            #+#    #+#             */
/*   Updated: 2021/10/27 14:19:33 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_map.h"

t_list	*ft_map_getbykey(t_map *map, t_list *value, char *key)
{
	t_map_elm	*elm;

	elm = map->root;
	while (elm)
	{
		if (!ft_strncmp(elm->key, key, elm->size_key + 1))
		{
			value->content = elm->value;
			value->content_size = elm->size_value;
			return (value);
		}
		elm = elm->next;
	}
	return (NULL);
}

t_map_elm	*ft_map_get_elm(t_map *map, char *key)
{
	t_map_elm	*elm;

	elm = map->root;
	while (elm && elm->key)
	{
		if (!ft_strncmp(key, elm->key, elm->size_key + 1))
			return (elm);
		elm = elm->next;
	}
	return (NULL);
}
