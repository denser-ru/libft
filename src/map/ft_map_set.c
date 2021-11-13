/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:47:17 by cayako            #+#    #+#             */
/*   Updated: 2021/11/12 13:34:28 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_map.h"

t_map	*ft_map_set(t_map *map, char *key, char *value)
{
	t_map_elm	*elm;

	elm = ft_map_get_elm(map, key);
	if (!elm)
		return (ft_map_add(map, key, value));
	if (elm->b_value)
	{
		ft_2lstcut(&map->big_value, elm->b_value, ft_lstdelcontent);
		elm->b_value = ft_2lstpushf(&map->big_value, value, ft_strlen(value));
		if (!elm->b_value)
		{
			ft_strncpy(map->err, "can`t get memory for ft_2lstnew()",
				FT_ERR_LEN);
			return (NULL);
		}
	}
	else
	{
		elm->size_value = ft_strlen(value);
		ft_strcpy(elm->value, value);
	}
	return (map);
}
