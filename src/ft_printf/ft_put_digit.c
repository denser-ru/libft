/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:23:44 by cayako            #+#    #+#             */
/*   Updated: 2021/10/27 12:32:25 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_digit_modifer(t_pf *pf)
{
	if (pf->flags & PF_H)
		return ((short)va_arg(*(pf->arg), long long));
	if (pf->flags & PF_HH)
		return ((char)va_arg(*(pf->arg), long long));
	if (pf->flags & PF_L)
		return ((long)va_arg(*(pf->arg), long long));
	if (pf->flags & PF_LL)
		return (va_arg(*(pf->arg), long long));
	return ((int)va_arg(*(pf->arg), long long));
}

void	ft_digit_prefix(t_pf *pf, int prec, int sgn)
{
	char	c;

	if (!(pf->flags & PF_ALIGN) && (!(pf->flags & PF_ZERO)
			|| (pf->flags & PF_PREC)))
		ft_putchar_n(pf->put, ' ', pf->width);
	if (pf->flags & PF_SPACE)
		c = ' ';
	else
		c = 0;
	if ((pf->flags & PF_PLUS) || sgn)
	{
		if (sgn)
			c = '-';
		else
			c = '+';
	}
	ft_putchar_n(pf->put, c, (pf->flags & PF_PLUS)
		|| sgn || (pf->flags & PF_SPACE));
	if (!(pf->flags & PF_ALIGN) && (pf->flags & PF_ZERO)
		&& !(pf->flags & PF_PREC))
		ft_putchar_n(pf->put, '0', pf->width);
	ft_putchar_n(pf->put, '0', prec);
}

void	ft_put_digit(t_pf *pf, long long nb, int size, int prec)
{
	int		sgn;
	int		z;

	nb = ft_digit_modifer(pf);
	sgn = nb < 0;
	if (sgn)
		nb = -nb;
	z = ((pf->flags & PF_PREC) && !(pf->precision) && !sgn && !nb);
	size = (ft_get_nblen_base(nb, 10) + 1) * !z;
	prec = (pf->precision - size) * ((pf->precision - size) > 0);
	size += ((pf->flags & PF_PLUS) || sgn || (pf->flags & PF_SPACE));
	pf->width = (pf->width - size - prec) * (pf->width - size - prec > 0);
	ft_digit_prefix(pf, prec, sgn);
	pf->i += pf->width + prec + size;
	if (!z)
		ft_put_atoi_base(pf, nb, 10, 'd');
	ft_putchar_n(pf->put, ' ', (pf->width) * !(!(pf->flags & PF_ALIGN)));
}
