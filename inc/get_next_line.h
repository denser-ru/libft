/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:57:33 by cayako            #+#    #+#             */
/*   Updated: 2021/11/14 13:59:39 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# define BUFF_SIZE		512
# define FT_LINE_BUF	512

typedef struct s_fdn
{
	int			fd;
	t_list		*lstline;
	void		*buf;
	void		*div;
	void		*tail;
	size_t		size;
	char		eof;
}				t_fdn;

/*
** int				get_next_line(const int fd, char **line);
*/

int	ft_gnl(int fd, char **line);

#endif
