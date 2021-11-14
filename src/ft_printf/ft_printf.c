/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:22:27 by cayako            #+#    #+#             */
/*   Updated: 2021/11/14 13:59:39 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_clear_args(t_pf *pf)
{
	pf->width = 0;
	pf->precision = 0;
	pf->flags = 0;
}

static void	init_printf(t_pf **pf, const char *format, va_list *arg)
{
	*pf = (t_pf *)ft_memalloc(sizeof(t_pf));
	(*pf)->put = (t_putmem *)ft_memalloc(sizeof(t_putmem));
	(*pf)->arg = arg;
	(*pf)->start = (char *)format;
	(*pf)->cur = (*pf)->start;
	(*pf)->next = ft_strchr((*pf)->cur, '%');
}

int	ft_printf(const char *format, ...)
{
	va_list		arg;
	t_pf		*pf;
	int			i;

	va_start(arg, format);
	init_printf(&pf, format, &arg);
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
	i = (int)pf->put->count;
	ft_memdel((void **)&pf->put);
	free(pf);
	return (i);
}
