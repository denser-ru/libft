/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:22:27 by cayako            #+#    #+#             */
/*   Updated: 2020/10/18 14:22:34 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_clear_args(t_pf *pf)
{
	pf->width = 0;
	pf->precision = 0;
	pf->flags = 0;
}

int	ft_printf(const char *format, ...)
{
	va_list		arg;
	t_pf		*pf;
	int			i;

	pf = (t_pf *)ft_memalloc(sizeof(t_pf));
	pf->put = (t_putmem *)ft_memalloc(sizeof(t_putmem));
	pf->arg = &arg;
	pf->start = (char *)format;
	pf->cur = pf->start;
	va_start(arg, format);
	pf->next = ft_strchr(pf->cur, '%');
	while (pf->next)
	{
		pf->i += (int)(pf->next - pf->cur);
		ft_putnstr_mem(pf->put, pf->cur, pf->next - pf->cur);
		pf->cur = pf->next + 1;
		ft_parsing(pf, pf->cur);
		ft_clear_args(pf);
		pf->next = ft_strchr(pf->cur, '%');
	}
	ft_putnstr_mem(pf->put, pf->cur, ft_strchr(pf->cur, '\0') - pf->cur);
	ft_putnstr(pf->put->mem, pf->put->count);
	i = pf->put->count;
	ft_memdel((void **)&pf->put);
	free(pf);
	return (i);
}
