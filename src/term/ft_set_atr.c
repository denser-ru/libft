/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 01:15:07 by cayako            #+#    #+#             */
/*   Updated: 2020/11/16 12:43:36 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term.h"
#include "ft_frame.h"
#include "libft.h"

void	ft_term_set_atr(int atr)
{
	char	buf[32];
	int		i;

	i = 0;
	ft_memcpy(buf, "\033[", 3);
	i += 3;
	i += ft_putnbr_to_mem(buf + i, atr);
	*(buf + i++) = 'm';
	ft_putnstr(buf, i);
}

void	ft_term_set_2atr(int atr1, int atr2)
{
	char	buf[64];
	int		i;

	i = 0;
	ft_memcpy(buf, "\033[", 3);
	i += 3;
	i += ft_putnbr_to_mem(buf + i, atr1);
	*(buf + i++) = ';';
	i += ft_putnbr_to_mem(buf + i, atr2);
	*(buf + i++) = 'm';
	ft_putnstr(buf, i);
}

void	ft_term_set_3atr(int atr1, int atr2, int atr3)
{
	char	buf[64];
	int		i;

	i = 0;
	ft_memcpy(buf, "\033[", 3);
	i += 3;
	i += ft_putnbr_to_mem(buf + i, atr1);
	*(buf + i++) = ';';
	i += ft_putnbr_to_mem(buf + i, atr2);
	*(buf + i++) = ';';
	i += ft_putnbr_to_mem(buf + i, atr3);
	*(buf + i++) = 'm';
	ft_putnstr(buf, i);
}
