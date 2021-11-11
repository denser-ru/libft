/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2lstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 08:57:56 by cayako            #+#    #+#             */
/*   Updated: 2021/11/09 13:44:22 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_2lstdel(t_2list **alst, void (*del)(void *, size_t))
{
	if (*alst != NULL && del != NULL)
	{
		ft_2lstdel(&((*alst)->next), del);
		ft_2lstdelone(alst, del);
	}
}
