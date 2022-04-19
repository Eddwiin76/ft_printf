/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:05:58 by tpierre           #+#    #+#             */
/*   Updated: 2020/03/10 12:34:11 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_flag_char(t_printf **list)
{
	char toprint;

	toprint = (char)va_arg((*list)->args, int);
	if ((*list)->width > 1 && !(*list)->minus)
	{
		if ((*list)->zero == 1)
			(*list)->nprinted += ft_putchar_zero_fd((*list)->width - 1, 1);
		else if ((*list)->zero == 0)
			(*list)->nprinted += ft_putchar_space_fd((*list)->width - 1, 1);
	}
	ft_putchar_fd(toprint, 1);
	(*list)->nprinted += 1;
	if ((*list)->width > 1 && (*list)->minus)
		(*list)->nprinted += ft_putchar_space_fd((*list)->width - 1, 1);
}
