/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_print_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:19:13 by cayako            #+#    #+#             */
/*   Updated: 2021/10/28 18:56:00 by cayako           ###   ########.fr       */
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
