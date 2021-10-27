/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:54:26 by cayako            #+#    #+#             */
/*   Updated: 2021/08/08 01:38:29 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getint()
{
    int				r;
    int             c;

    r = (int)read(0, &c, sizeof(c));
    if (r < 0)
        return (r);
    else
        return (c);
}
