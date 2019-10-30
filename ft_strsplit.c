/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:23:37 by cayako            #+#    #+#             */
/*   Updated: 2019/10/26 01:38:29 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strscount(const char *s, char c, int count)
{
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s != c && *(s + 1) != '\0')
				++s;
		}
		++s;
	}
	return (count);
}

static int		ft_crtmp(const char *s, char **tmp, char c, int l)
{
	*tmp = ft_strdup(s);
	while ((*tmp)[l])
	{
		if ((*tmp)[l] == c)
			(*tmp)[l] = '\0';
		++l;
	}
	return (l);
}

static void		ft_strtosplit(char **buf, const char *s, char c)
{
	char	*tmp;
	int		l;
	int		i;

	i = 0;
	l = ft_crtmp(s, &tmp, c, 0);
	while (i < l)
	{
		if (tmp[i])
		{
			*buf = ft_strdup(&tmp[i]);
			i += ft_strlen(&tmp[i]);
			++buf;
			--i;
		}
		++i;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char	**buf;
	int		l;

	if (!s)
		return (NULL);
	l = ft_strscount(s, c, 0);
	if (!(buf = (char **)malloc(sizeof(char *) * (l + 1))))
		return (NULL);
	buf[l] = NULL;
	ft_strtosplit(buf, s, c);
	return (buf);
}
