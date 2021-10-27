/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstputstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 00:51:56 by cayako            #+#    #+#             */
/*   Updated: 2021/06/27 00:57:29 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	ft_lstputendl(t_list *lst)
{
    if (lst)
    {
        ft_putnstr(lst->content, lst->content_size);
        ft_putchar('\n');
    }
}
