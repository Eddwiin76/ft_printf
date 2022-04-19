/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_adr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 18:41:59 by tpierre           #+#    #+#             */
/*   Updated: 2020/03/13 04:34:21 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_end(t_printf **list, unsigned long toprint)
{
	ft_putstr_fd("0x", 1);
	(*list)->nprinted += 2;
	if ((*list)->prec > 0 && (*list)->dot == 1)
	{
		ft_putchar_zero_fd((*list)->prec - (*list)->len, 1);
		if ((*list)->prec - (*list)->len > 0)
			(*list)->nprinted += (*list)->prec - (*list)->len;
	}
	if (!((*list)->prec == 0 && (*list)->dot == 1 && toprint == 0))
	{
		ft_putadr_fd(toprint, 1);
		(*list)->nprinted += (*list)->len;
	}
}

void	ft_next(t_printf **list, unsigned long toprint, int zero)
{
	int iflen;

	if ((*list)->len > 0)
		iflen = 2;
	else
		iflen = 0;
	if (zero && !((*list)->prec == 0 && (*list)->dot == 1 && toprint == 0))
		iflen += 1;
	if (((*list)->width - ((iflen + (*list)->len) - zero) > 0)
			&& !(*list)->minus)
	{
		ft_putchar_space_fd((*list)->width -
				((iflen + (*list)->len) - zero), 1);
		(*list)->nprinted += (*list)->width - ((iflen + (*list)->len) - zero);
	}
	ft_end(list, toprint);
	if (((*list)->width - ((iflen + (*list)->len) - zero) > 0
			&& (*list)->minus))
	{
		ft_putchar_space_fd((*list)->width -
				((iflen + (*list)->len) - zero), 1);
		(*list)->nprinted += (*list)->width - ((iflen + (*list)->len) - zero);
	}
}

void	ft_flag_adr(t_printf **list)
{
	unsigned long	toprint;
	unsigned long	nbr;
	int				zero;

	zero = 0;
	toprint = (unsigned long)va_arg((*list)->args, void *);
	nbr = toprint;
	while ((nbr /= 16) > 0)
		(*list)->len++;
	if (toprint == 0)
		zero = 1;
	else
		zero = 0;
	ft_next(list, toprint, zero);
}
