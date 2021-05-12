/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frame.c                                         :+:      :+:    :+:   */
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

static void	ft_put_line(int w, char *l, char *m, char *r)
{
	ft_putstr(l);
	while (w-- > 0)
		ft_putstr(m);
	ft_putstr(r);
}

void	ft_frame(t_frame f)
{
	ft_term_set_2atr(f.fg, f.bg);
	ft_term_goto(f.x, f.y);
	ft_put_line(f.w - 2, "┌", "─", "┐");
	ft_term_goto(f.x, f.y + (f.h)--);
	ft_put_line(f.w - 2, "└", "─", "┘");
	while (f.h > 0)
	{
		ft_term_goto(f.x, f.y + (f.h)--);
		ft_put_line(f.w - 2, "│", " ", "│");
	}
	ft_putstr(ESC RESETCOLOR);
}

void	ft_clear_line(int x, int y, int fg, int bg)
{
	ft_term_goto(x, y);
	ft_term_set_2atr(fg, bg);
	ft_putstr("                ");
}
