/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_src.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:24:58 by cayako            #+#    #+#             */
/*   Updated: 2020/10/18 14:25:06 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_put_percent(t_pf *pf)
{
	int		space;

	space = pf->width > 1 ? pf->width - 1 : 0;
	if (!(pf->flags & PF_ALIGN))
		ft_putchar_n(pf->put, ' ', space);
	ft_putchar_mem(pf->put, '%');
	if (pf->flags & PF_ALIGN)
		ft_putchar_n(pf->put, ' ', space);
	(pf->i) += 1 + space;
}

void		ft_put_pf_char(t_pf *pf, char c)
{
	int		space;

	c = va_arg(*(pf->arg), int);
	space = pf->width > 1 ? pf->width - 1 : 0;
	if (!(pf->flags & PF_ALIGN))
		ft_putchar_n(pf->put, ' ', space);
	ft_putchar_mem(pf->put, c);
	if (pf->flags & PF_ALIGN)
		ft_putchar_n(pf->put, ' ', space);
	(pf->i) += 1 + space;
}

void		ft_put_pf_str(t_pf *pf, char *s)
{
	int		len;
	int		space;

	s = va_arg(*(pf->arg), char*);
	if (!s && (pf->i += 6))
	{
		ft_putstr_mem(pf->put, "(null)");
		return ;
	}
	len = ft_strlen(s);
	if (pf->flags & PF_PREC)
		len = len > pf->precision ? pf->precision : len;
	space = pf->width > len ? pf->width - len : 0;
	if (!(pf->flags & PF_ALIGN))
		ft_putchar_n(pf->put, ' ', space);
	ft_putnstr_mem(pf->put, s, len);
	if (pf->flags & PF_ALIGN)
		ft_putchar_n(pf->put, ' ', space);
	(pf->i) += len + space;
}
