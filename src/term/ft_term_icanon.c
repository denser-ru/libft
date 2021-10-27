/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 01:15:07 by cayako            #+#    #+#             */
/*   Updated: 2021/10/27 14:17:11 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term.h"

void	ft_term_icanon(ft_term	*last_term, ft_term	*term)
{
	tcgetattr(0, term);
	tcgetattr(0, last_term);
	term->c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, term);
}
