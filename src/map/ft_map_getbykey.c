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

static int	check_key(char *key, t_map_elm *elm);
static int	check_b_key(char *key, t_map_elm *elm);

t_list	*ft_map_getbykey(t_map *map, t_list *value, char *key)
{
	t_map_elm	*elm;
	int			(*f)(char *, t_map_elm *);

	elm = map->root;
	if (ft_strlen(key))
		f = check_key;
	else
		f = check_b_key;
	while (elm && (*elm->key || elm->b_key))
	{
		if (!f(key, elm))
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
	int			(*f)(char *, t_map_elm *);

	elm = map->root;
	if (ft_strlen(key))
		f = check_key;
	else
		f = check_b_key;
	while (elm && (*elm->key || elm->b_key))
	{
		if (!f(key, elm))
			return (elm);
		elm = elm->next;
	}
	return (NULL);
}

static int	check_key(char *key, t_map_elm *elm)
{
	return (ft_strncmp(key, elm->key, elm->size_key + 1));
}

static int	check_b_key(char *key, t_map_elm *elm)
{
	return (ft_strncmp(key, elm->b_key->content, elm->b_key->content_size + 1));
}