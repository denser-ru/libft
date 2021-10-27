/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 04:49:01 by cayako            #+#    #+#             */
/*   Updated: 2020/11/16 13:14:37 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_H
# define TERM_H

# include "libft.h"
# include "term.h"
# include <termios.h>

# define ESC "\033"

/*
** home() -  Move cursor to the indicated row, column (origin at 1,1)
** clrscr -  Clear the screen, move to (1,1)
** clr_to_r - Удаляет часть строки. Если n равно нулю (или отсутствует),
** 		очищает всё от курсора до конца строки. Если n равно единице, очищает
** 		всё от курсора до начала строки. Если n равно двум, очищает всю строку.
** 		Положение курсора не меняется.
*/
# define CLRSRC					"[2J"

# define CLRSRC_N					'J'
# define MOVE						'A'

/*
** Save Cursor & Attrs	*ESC*7	Сохраняет текущую позицию курсора вместе с
** 		атрибутами (цвет?).
** Restore Cursor & Attrs	*ESC*8
*/

/*
** Set Display Attribute Mode	<ESC>[{attr1};...;{attrn}m
*/
# define RESETCOLOR			"[0m"

/*
** Format text
*/
# define RESET		0
# define BRIGHT		1
# define DIM		2
# define UNDERSCORE	3
# define BLINK		4
# define REVERSE	5
# define HIDDEN		6

/*
** Foreground Colours (text)
*/
# define F_BLACK	30
# define F_RED		31
# define F_GREEN	32
# define F_YELLOW	33
# define F_BLUE		34
# define F_MAGENTA	35
# define F_CYAN		36
# define F_WHITE	37

/*
** Background Colours
*/
# define B_BLACK	40
# define B_RED		41
# define B_GREEN	42
# define B_YELLOW	44
# define B_BLUE		44
# define B_MAGENTA	45
# define B_CYAN		46
# define B_WHITE	47

typedef struct termios	t_term;

void				get_term_size(unsigned int *width, unsigned int *height);
size_t				ft_term_goto_mem(char *out, unsigned int row,
						   unsigned int col);
void				ft_term_goto(unsigned int col, unsigned int row);
void				ft_term_set_atr(int atr);
void				ft_term_set_2atr(int atr1, int atr2);
void				ft_term_set_3atr(int atr1, int atr2, int atr3);
void				ft_term_cmd_atr(int atr, char c);
void				ft_term_cmd_2atr(int atr1, int atr2, char c);

void				ft_term_get_xy(size_t *xy);
void				ft_term_icanon(t_term *last_term, t_term	*term);

#endif
