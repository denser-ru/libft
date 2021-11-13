/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_getbykey.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:19:33 by cayako            #+#    #+#             */
/*   Updated: 2021/11/09 17:51:38 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_map.h"

t_list	*ft_map_getbykey(t_map *map, t_list *value, char *key)
{
	t_map_elm	*elm;

	elm = map->root;
	while (elm && elm->key && elm->key->content)
	{
		if (!ft_strncmp(key, elm->key->content, elm->key->content_size + 1))
		{
			value->content = elm->value->content;
			value->content_size = elm->value->content_size;
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
	while (elm && elm->key && elm->key->content)
	{
		if (!ft_strncmp(key, elm->key->content, elm->key->content_size + 1))
			return (elm);
		elm = elm->next;
	}
	return (NULL);
}
