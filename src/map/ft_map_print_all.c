/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_print_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:19:13 by cayako            #+#    #+#             */
/*   Updated: 2021/11/11 11:03:56 by denser           ###   ########.fr       */
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
		if (elm->b_key)
			ft_putnstr(elm->b_key->content, elm->b_key->content_size);
		else
			ft_putnstr(elm->key, elm->size_key);
		ft_putchar('=');
		if (elm->b_value)
			ft_putnstr(elm->b_value->content, elm->b_value->content_size);
		else
			ft_putnstr(elm->value, elm->size_value);
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
		ft_putchar((char)('0' + (elm->size_key > 0)));
		ft_putchar('\t');
		if (elm->b_key)
			ft_putnstr(elm->b_key->content, elm->b_key->content_size);
		else
			ft_putnstr(elm->key, elm->size_key);
		if (!elm->size_key)
			ft_putstr("\t---\t");
		ft_putchar('=');
		if (elm->b_value)
			ft_putnstr(elm->b_value->content, elm->b_value->content_size);
		else
			ft_putnstr(elm->value, elm->size_value);
		ft_putchar('\n');
		++elm;
	}
}

void	ft_map_stat(t_map *map)
{
	ft_printf("\nsize: %d, count: %d, deleted: %d", map->size,
		map->count, map->deleted);
	ft_putchar('\n');
}