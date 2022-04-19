/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 18:47:30 by tpierre           #+#    #+#             */
/*   Updated: 2020/03/13 03:59:45 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_int_0(t_printf **list)
{
	if ((*list)->width == 0 && (*list)->dot == 1 && (*list)->prec == 0)
		return (-1);
	if ((*list)->width != 0 && (*list)->dot == 1 && (*list)->prec == 0)
	{
		(*list)->nprinted += ft_putchar_space_fd((*list)->width, 1);
		return (-1);
	}
	return (1);
}

void	ft_minus_0(int n, t_printf **list)
{
	int len;

	len = (*list)->len;
	if ((*list)->width > len && (*list)->zero == 0)
		(*list)->nprinted += ft_putchar_space_fd((*list)->width - len, 1);
	else if ((*list)->width > len && (*list)->zero == 1)
	{
		if (n == -1 && (*list)->width >= (*list)->prec && (*list)->dot == 1)
			(*list)->nprinted += ft_putchar_space_fd((*list)->width - len, 1);
		else if (n == 0 && (*list)->width >= (*list)->prec && (*list)->dot == 1)
			(*list)->nprinted += ft_putchar_space_fd((*list)->width - len, 1);
		else
		{
			if (n == -1)
			{
				ft_putchar_fd('-', 1);
				n = 1;
			}
			(*list)->nprinted += ft_putchar_zero_fd((*list)->width - len, 1);
		}
	}
	if (n == -1)
		ft_putchar_fd('-', 1);
}

void	ft_flag_int_more(t_printf **list, int n, int nbr, int toprint)
{
	if (n == -1)
		(*list)->len++;
	if (toprint == 0)
		if (ft_int_0(list) == -1)
			return ;
	if ((*list)->minus == 0)
		ft_minus_0(n, list);
	if (n == -1 && (*list)->minus == 1 && (*list)->zero == 0)
		ft_putchar_fd('-', 1);
	if ((*list)->prec > nbr)
		ft_putchar_zero_fd((*list)->prec - nbr, 1);
	if (toprint == -2147483648)
	{
		ft_putnbr_fd(2147, 1);
		ft_putnbr_fd(483648, 1);
	}
	else
		ft_putnbr_fd(toprint, 1);
	(*list)->nprinted += (*list)->len;
	if ((*list)->minus == 1 && (*list)->width > (*list)->len)
		(*list)->nprinted +=
				ft_putchar_space_fd((*list)->width - (*list)->len, 1);
}

void	ft_flag_int(t_printf **list)
{
	int toprint;
	int nbr;
	int n;

	n = 0;
	toprint = (int)va_arg((*list)->args, int);
	if (toprint == -2147483648)
		(*list)->len = 10;
	if (toprint < 0)
	{
		if (toprint != -2147483648)
			toprint *= -1;
		n = -1;
	}
	nbr = toprint;
	while ((nbr /= 10) > 0 && toprint != -2147483648)
		(*list)->len++;
	nbr = (*list)->len;
	if ((*list)->prec > 0 && (*list)->prec > (*list)->len)
		(*list)->len = (*list)->prec;
	ft_flag_int_more(list, n, nbr, toprint);
}
