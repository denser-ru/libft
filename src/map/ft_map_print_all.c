/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_print_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:19:13 by cayako            #+#    #+#             */
/*   Updated: 2021/11/14 13:59:39 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_map.h"

void	ft_map_print_all(t_map *map)
{
	t_map_elm	*elm;

	elm = map->root;
	while (elm)
	{
		ft_putnstr(elm->key->content, elm->key->content_size);
		ft_putchar('=');
		ft_putnstr(elm->value->content, elm->value->content_size);
		ft_putchar('\n');
		elm = elm->next;
	}
}

void	ft_map_print_all_arr(t_map *map)
{
	t_map_elm	*elm;

	elm = map->arr;
	while (elm && elm != map->last)
	{
		if (elm->key)
		{
			ft_putchar((char) ('0' + (elm->key->content_size > 0)));
			ft_putchar('\t');
			ft_putnstr(elm->key->content, elm->key->content_size);
			ft_putchar('=');
			ft_putnendl(elm->value->content, elm->value->content_size);
		}
		else
			ft_putendl("0\t --- \t");
		++elm;
	}
}

void	ft_map_stat(t_map *map)
{
	ft_printf("\nsize: %d, count: %d, deleted: %d", map->size,
		map->count, map->deleted);
	ft_putchar('\n');
}