/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstputstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 00:51:56 by cayako            #+#    #+#             */
/*   Updated: 2021/10/27 14:12:54 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstputendl_fd(t_list *lst, int fd)
{
	if (lst)
		ft_putnendl_fd(lst->content, lst->content_size, fd);
}
