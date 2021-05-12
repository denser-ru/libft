/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clashund <clashund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:38:58 by smanta            #+#    #+#             */
/*   Updated: 2021/04/10 22:38:05 by clashund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*join_str_float(t_convs *p_convs, char *units, char *fract)
{
	char	*final_str;
	size_t	len_units;
	size_t	len_fract;
	size_t	index;
	size_t	index_fin_str;

	len_units = ft_strlen(units);
	len_fract = ft_strlen(fract);
	final_str = (char *)malloc(sizeof(char) * (len_units + len_fract + 1
				+ (p_convs->precision > 0 || p_convs->sharp == 1)));
	if (final_str == NULL)
		return (NULL);
	index = -1;
	while (++index < len_units)
		final_str[index] = units[index];
	if (p_convs->precision > 0 || p_convs->sharp == 1)
		final_str[index++] = '.';
	index_fin_str = index;
	index = -1;
	while (++index < len_fract)
		final_str[index_fin_str + index] = fract[index];
	final_str[index_fin_str + index] = '\0';
	return (final_str);
}

static char	*get_fractional(int precision, long double fr)
{
	char	*fract;
	int		i;
	int		num;

	fract = (char *)malloc(sizeof(char) * (precision + 1));
	if (fract == NULL)
		return (NULL);
	i = 0;
	while (i < precision)
	{
		fr = fr * 10;
		num = (unsigned int)fr;
		fr -= num;
		fract[i] = num + comp_out(i == precision - 1 && fr * 10 >= 5
				&& precision >= 20, 1, 0) + '0';
		++i;
	}
	fract[precision] = '\0';
	return (fract);
}

char	*get_str_float(t_convs *p_convs, long double dval)
{
	unsigned long long	un;
	long double			fr;
	char				*units;
	char				*fract;
	char				*sval;

	un = (unsigned long long)dval;
	fr = dval - (long double)un;
	units = ft_ulltoa_base(un, 10);
	fract = get_fractional(p_convs->precision, fr);
	sval = join_str_float(p_convs, units, fract);
	free(units);
	free(fract);
	return (sval);
}

int	comp_out(int comp, int first, int second)
{
	if (comp)
		return (first);
	else
		return (second);
}

size_t	compll_out(int comp, unsigned long long val)
{
	if (comp)
		return (ft_putnbrull((unsigned long long)val));
	else
		return (ft_putnbrull(val));
}
