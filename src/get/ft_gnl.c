/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:54:26 by cayako            #+#    #+#             */
/*   Updated: 2021/10/28 12:24:04 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static size_t	get_line(char *line, char *buf, size_t len);

static int	ft_mem_resize(char **mem, size_t size1, size_t size2)
{
	char	*new;

	if (size2 <= size1)
		return (-1);
	if (!*mem)
	{
		*mem = (char *)ft_memalloc(size2);
		return ((int)size2);
	}
	new = (char *)malloc(size2);
	ft_memcpy(new, *mem, size1);
	ft_bzero(new + size1, size2 - size1);
	free(*mem);
	*mem = new;
	return ((int)(size2 - size1));
}

int	ft_gnl(int fd, char **line)
{
	static char		buf[FT_LINE_BUF + 1];
	static char		*p = buf;
	size_t			len;

	if (p == buf)
		len = read(fd, p, FT_LINE_BUF);
	if (!*line)
		if (ft_mem_resize(line, 0, FT_LINE_BUF + 1) == -1)
			return (-1);
	len = get_line(*line, p, FT_LINE_BUF);
	if (!len && p == buf)
		return (-1);
	p += len;
	while (*p != '\n')
	{
		p = buf;
		if (ft_mem_resize(line, len + 1, len + read(fd, buf, FT_LINE_BUF) + 1) < 0)
			break ;
		p += get_line(*line + len, p, FT_LINE_BUF);
		len += p - buf;
	}
	if (*p != '\n')
		return (-1);
	(*line)[len] = '\0';
	*p = '\0';
	return ((int)(p++ - buf));
}

static size_t	get_line(char *line, char *buf, size_t len)
{
	size_t	size;

	size = 0;
	while (size < len && *buf && *buf != '\n')
	{
		*line = *buf;
		++line;
		++buf;
		++size;
	}
	return (size);
}
