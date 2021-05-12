/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ox.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clashund <clashund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 19:25:48 by clashund          #+#    #+#             */
/*   Updated: 2021/04/10 20:51:09 by clashund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_compare_out_x(int comp, int flag, char *str, char *temp_str)
{
	if (flag)
	{
		if (comp)
			write(1, "0x", 2);
		else
			write(1, "0X", 2);
	}
	else
	{
		if (comp)
			ft_putstr(str);
		else
			ft_putstr(temp_str);
	}
}
