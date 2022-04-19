/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:32:43 by tpierre           #+#    #+#             */
/*   Updated: 2020/03/13 03:54:10 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_hexa_0(t_printf **list)
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

void	ft_hexaminus_0(int n, t_printf **list)
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

void	ft_flag_hexa_more(t_printf **list, int n,
			unsigned int nbr, unsigned int toprint)
{
	if (toprint == 0)
		if (ft_hexa_0(list) == -1)
			return ;
	if ((*list)->minus == 0)
		ft_hexaminus_0(n, list);
	if (n == -1 && (*list)->minus == 1 && (*list)->zero == 0)
		ft_putchar_fd('-', 1);
	if ((*list)->prec > (int)nbr)
		ft_putchar_zero_fd((*list)->prec - nbr, 1);
	ft_puthexa_fd(toprint, 1);
	(*list)->nprinted += (*list)->len;
	if ((*list)->minus == 1 && (*list)->width > (*list)->len)
		(*list)->nprinted +=
				ft_putchar_space_fd((*list)->width - (*list)->len, 1);
}

void	ft_flag_hexa(t_printf **list)
{
	unsigned int	toprint;
	unsigned int	nbr;
	int				n;

	n = 0;
	toprint = (unsigned int)va_arg((*list)->args, unsigned int);
	if (toprint < 0)
	{
		toprint *= -1;
		n = -1;
	}
	nbr = toprint;
	while ((nbr /= 16) > 0)
		(*list)->len++;
	nbr = (*list)->len;
	if ((*list)->prec > 0 && (*list)->prec > (*list)->len)
		(*list)->len = (*list)->prec;
	if (n == -1)
		(*list)->len++;
	ft_flag_hexa_more(list, n, nbr, toprint);
}
