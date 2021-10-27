/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_print_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denser <denser@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:19:13 by denser            #+#    #+#             */
/*   Updated: 2021/10/27 14:19:23 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_map.h"

void	ft_map_print_all(t_map_elm *arr)
{
	while (arr)
	{
		ft_putnstr(arr->key, arr->size_key);
		ft_putchar('=');
		ft_putnstr(arr->value, arr->size_value);
		ft_putchar('\n');
		arr = arr->next;
	}
}
