/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 01:15:07 by cayako            #+#    #+#             */
/*   Updated: 2021/11/14 13:59:39 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term.h"
#include "libft.h"

void	ft_term_get_xy(size_t *xy)
{
	char	buf[24];
	char	*p;
	t_term	last_term;
	t_term	term;

	ft_term_icanon(&last_term, &term);
	xy[0] = 0;
	p = buf;
	*p = write(1, ESC "[6n", sizeof(ESC "[6n"));
	while (21)
	{
		*p = (char)ft_getch();
		if (*(p++) == 'R')
			break ;
	}
	*p = '\0';
	p = buf + 2;
	xy[0] = ft_atoi(p);
	while (*p)
		if (*(p++) == ';')
			break ;
	xy[1] = ft_atoi(p);
	tcsetattr(0, TCSANOW, &last_term);
}
