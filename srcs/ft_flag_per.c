/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_per.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:14:12 by tpierre           #+#    #+#             */
/*   Updated: 2020/03/10 17:06:43 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_flag_per(t_printf **list)
{
	(void)list;
	if ((*list)->width > 1 && !(*list)->minus)
	{
		if ((*list)->zero == 1)
			(*list)->nprinted += ft_putchar_zero_fd((*list)->width - 1, 1);
		else if ((*list)->zero == 0)
			(*list)->nprinted += ft_putchar_space_fd((*list)->width - 1, 1);
	}
	ft_putchar_fd('%', 1);
	(*list)->nprinted += 1;
	if ((*list)->width > 1 && (*list)->minus)
		(*list)->nprinted += ft_putchar_space_fd((*list)->width - 1, 1);
}
