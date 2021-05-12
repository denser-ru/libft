/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_whats.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clashund <clashund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:14:02 by clashund          #+#    #+#             */
/*   Updated: 2021/04/09 21:54:39 by clashund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_flag(char c)
{
	if (ft_strchr("#0- +", c))
		return (1);
	return (0);
}

int	is_length(char c)
{
	if (ft_strchr("hlL", c))
		return (1);
	return (0);
}

int	is_conversion(int c)
{
	if (ft_strchr("cspdiouxXf%", c))
		return (1);
	return (0);
}
