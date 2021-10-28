/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_oxup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:24:33 by cayako            #+#    #+#             */
/*   Updated: 2021/10/27 13:58:31 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline static void	get_hex(int base, unsigned long long *hex,
								unsigned long long *div)
{
	*hex /= base;
	while (*hex)
	{
		*div *= base;
		*hex /= base;
	}
	*div *= base;
	*div /= base;
}

void	ft_put_atoi_base(t_pf *pf, unsigned long long int nb, int base, char f)
{
	unsigned long long		hex;
	unsigned long long		div;
	unsigned long long		nb2;
	const char				*abc = "0123456789abcdef0123456789ABCDEF";

	if (nb < (unsigned long long)base)
	{
		ft_putchar_mem(pf->put, abc[nb + 16 * (f == 'X')]);
		return ;
	}
	hex = nb / base;
	nb2 = nb / base;
	nb -= nb2 * base;
	div = 1;
	get_hex(base, &hex, &div);
	while (div)
	{
		hex = nb2 / div;
		ft_putchar_mem(pf->put, abc[hex + 16 * (f == 'X')]);
		nb2 -= hex * div;
		div /= base;
	}
	ft_putchar_mem(pf->put, abc[nb + 16 * (f == 'X')]);
}

void	ft_put_prefix(t_pf *pf, char f, int *width, unsigned long long nb)
{
	if (!(pf->flags & PF_ALIGN) && !(pf->flags & PF_ZERO))
		ft_putchar_n(pf->put, ' ', *width);
	if (f == 'p' && !(pf->flags & PF_PLUS))
		ft_putchar_n(pf->put, ' ',
			((pf->flags & PF_PLUS) || (pf->flags & PF_SPACE)) && f == 'p');
	else
		ft_putchar_n(pf->put, '+',
			((pf->flags & PF_PLUS) || (pf->flags & PF_SPACE)) && f == 'p');
	if ((pf->flags & PF_SHARP) && f == 'o' && nb)
		ft_putchar_mem(pf->put, '0');
	else if ((pf->flags & PF_SHARP) && f != 'u' && nb)
	{
		if (f == 'X')
			ft_putnstr_mem(pf->put, "0X", 2);
		else
			ft_putnstr_mem(pf->put, "0x", 2);
	}
	if (*width < 0)
		*width = 0;
	if (!(pf->flags & PF_ALIGN) && (pf->flags & PF_ZERO))
		ft_putchar_n(pf->put, '0', *width);
}

void	ft_put_x(t_pf *pf, char f, int base, unsigned long long int nb)
{
	int		size;
	int		width;
	int		prec;
	int		z;

	size = 1;
	z = ((pf->flags & PF_PREC) && !(pf->precision) && !nb
			&& !((pf->flags & PF_SHARP) && f == 'o'));
	size += -1 * (z != 0) + (z == 0) * ft_get_nblen_base(nb, base);
	if ((pf->flags & PF_SHARP) && (f == 'o' || f == 'x' || f == 'X'
			|| f == 'p') && nb)
		size += 1 + (f == 'o');
	prec = (pf->precision - size) * ((pf->precision - size) > 0);
	width = (pf->width - size - prec) * (pf->width - size - prec > 0);
	ft_put_prefix(pf, f, &width, nb);
	pf->i += width + size + prec;
	if ((pf->flags & PF_PREC) && prec)
		ft_putchar_n(pf->put, '0', prec);
	if (!z)
		ft_put_atoi_base(pf, nb, base, f);
	if (width && (pf->flags & PF_ALIGN))
		ft_putchar_n(pf->put, ' ', width);
}

void	ft_put_oxup(t_pf *pf, char f, int base)
{
	if (f == 'p')
		pf->flags = pf->flags | PF_LL | PF_SHARP;
	if (pf->flags & PF_LL)
		ft_put_x(pf, f, base, va_arg(*(pf->arg), unsigned long long int));
	else if (pf->flags & PF_L)
		ft_put_x(pf, f, base, va_arg(*(pf->arg), unsigned long int));
	else
		ft_put_x(pf, f, base, va_arg(*(pf->arg), unsigned int));
}
