/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:24:14 by cayako            #+#    #+#             */
/*   Updated: 2021/11/14 13:59:39 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_lli(t_pf *pf, unsigned long long nb, int size)
{
	unsigned long long	div;
	int					len;

	div = 10;
	len = 0;
	while ((nb / div))
		div *= 10;
	div /= 10;
	while (div && (size--) && (++len))
	{
		ft_putchar_mem(pf->put, '0' + nb / div);
		nb = nb - (nb / div) * div;
		div /= 10;
	}
	return (len);
}

int	ft_put_llf(t_pf *pf, long double nb, int prec)
{
	while (prec--)
		nb *= 10;
	ft_put_lli(pf, (unsigned long long)(nb + 0.5), prec);
	return (prec);
}

void	ft_get_f(t_pf *pf, long long *n, long double *d)
{
	long double		nb;

	if (pf->flags & PF_ML)
		nb = va_arg(*(pf->arg), long double);
	else if (pf->flags & PF_LL)
		nb = va_arg(*(pf->arg), double);
	else
		nb = va_arg(*(pf->arg), double);
	*n = (long long)nb;
	*d = nb - *n;
}

void	ft_f_prefix(t_pf *pf, int *len, int prec, long long n)
{
	if (!(pf->flags & PF_ALIGN) && !(pf->flags & PF_ZERO))
		ft_putchar_n(pf->put, ' ', len[0]);
	if (((n < 0) || (pf->flags & PF_PLUS)) && ++(pf->i))
	{
		if (n < 0)
			ft_putchar_mem(pf->put, '-');
		else
			ft_putchar_mem(pf->put, '+');
	}
	if (((pf->flags & PF_SPACE) && !(pf->flags & PF_PLUS) && n >= 0))
		ft_putchar_mem(pf->put, ' ');
	if (!(pf->flags & PF_ALIGN) && (pf->flags & PF_ZERO))
		ft_putchar_n(pf->put, '0', len[0]);
	pf->i += ft_put_lli(pf, ft_abs(n), len[1]) + len[0] + prec + 1;
	if ((prec || (pf->flags & PF_PREC)))
		ft_putchar_mem(pf->put, '.');
}

void	ft_put_f(t_pf *pf)
{
	long long		n;
	long double		d;
	int				prec;
	int				len[4];

	prec = pf->precision;
	if (!(pf->flags & PF_PREC))
		prec = 6;
	prec *= !((pf->flags & PF_PREC) && !(pf->precision));
	ft_get_f(pf, &n, &d);
	len[1] = ft_get_nblen_base(ft_abs(n), 10) + 1
		+ ((prec || (pf->flags & PF_PREC)) > 0);
	len[1] = ft_get_nblen_base(ft_abs(n), 10) + 1
		+ ((prec || (pf->flags & PF_PREC)) > 0);
	len[2] = prec;
	len[0] = (pf->width - len[1] - len[2]) * (len[1] + len[2] < pf->width);
	len[0] -= ((pf->flags & PF_PLUS) || (pf->flags & PF_SPACE) || (n < 0));
	if (len[0] < 0)
		len[0] = 0;
	ft_f_prefix(pf, len, prec, n);
	ft_put_llf(pf, ft_abs_ld(d), prec);
	if (pf->flags & PF_ALIGN)
		ft_putchar_n(pf->put, ' ', len[0]);
	ft_putchar_n(pf->put, '0', prec - len[2]);
}
