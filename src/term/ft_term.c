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

size_t	ft_term_goto_mem(char *out, unsigned int row, unsigned int col)
{
	size_t	i;

	i = 0;
	ft_memcpy(out, "\033[", 3);
	i += 2;
	i += ft_putnbr_to_mem(out + i, col);
	*(out + i++) = ';';
	i += ft_putnbr_to_mem(out + i, row);
	*(out + i++) = 'H';
	return (i);
}

void	ft_term_goto(unsigned int row, unsigned int col)
{
	char	buf[64];
	size_t	i;

	i = ft_term_goto_mem(buf, row, col);
	ft_putnstr(buf, i);
}

void	ft_term_cmd_atr(int atr, char c)
{
	char	buf[32];
	int		i;

	i = 0;
	ft_memcpy(buf, "\033[", 3);
	i += 3;
	i += ft_putnbr_to_mem(buf + i, atr);
	*(buf + i++) = c;
	ft_putnstr(buf, i);
}

void	ft_term_cmd_2atr(int atr1, int atr2, char c)
{
	char	buf[64];
	int		i;

	i = 0;
	ft_memcpy(buf, "\033[", 3);
	i += 3;
	i += ft_putnbr_to_mem(buf + i, atr1);
	*(buf + i++) = ';';
	i += ft_putnbr_to_mem(buf + i, atr2);
	*(buf + i++) = c;
	ft_putnstr(buf, i);
}
