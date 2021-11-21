/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frame.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 01:23:50 by cayako            #+#    #+#             */
/*   Updated: 2021/11/14 13:59:39 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRAME_H
# define FT_FRAME_H

# include "ft_term.h"

typedef struct s_frame
{
	int			x;
	int			y;
	int			w;
	int			h;
	int			fg;
	int			bg;
}				t_frame;

void			ft_frame(t_frame f);

#endif
