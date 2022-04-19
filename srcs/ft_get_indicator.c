/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_indicator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:15:50 by tpierre           #+#    #+#             */
/*   Updated: 2020/03/13 04:10:29 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_get_flag(t_printf **list)
{
	int i;

	i = -1;
	while ((*list)->fs[++i])
	{
		if ((*list)->fs[i] == '-')
		{
			if ((*list)->dot == 0)
				(*list)->minus = 1;
			else if ((*list)->dot == 1)
				(*list)->minusprec = 1;
		}
		else if ((*list)->fs[i] == '*')
			(*list)->star = 1;
		else if ((*list)->fs[i] == '.')
			(*list)->dot = 1;
		else if ((*list)->fs[i] == '#')
			(*list)->hash = 1;
		else if ((*list)->fs[i] == ' ')
			(*list)->space = 1;
		else if ((*list)->fs[i] == '+')
			(*list)->plus = 1;
	}
}

void	ft_get_width(t_printf **list)
{
	while ((ft_strchr("-# +", (*list)->fs[(*list)->pos]))
			&& (*list)->fs[(*list)->pos] != '\0')
		(*list)->pos += 1;
	if ((*list)->fs[(*list)->pos] == '0')
	{
		(*list)->zero = 1;
		(*list)->pos += 1;
	}
	while ((*list)->fs[(*list)->pos] == '0' || (*list)->fs[(*list)->pos] == '-')
		(*list)->pos += 1;
	ft_get_length(list, 0);
	if ((*list)->fs[(*list)->pos] == '*')
	{
		(*list)->width = va_arg((*list)->args, int);
		(*list)->pos += 1;
	}
}

void	ft_get_prec(t_printf **list)
{
	int		tmp;
	char	*tmpatoi;

	if ((*list)->fs[(*list)->pos] == '.')
	{
		(*list)->pos += 1;
		while ((*list)->fs[(*list)->pos] == '0')
			(*list)->pos += 1;
		if ((*list)->fs[(*list)->pos] >= '1'
			&& (*list)->fs[(*list)->pos] <= '9')
		{
			tmpatoi = &(*list)->fs[(*list)->pos];
			(*list)->prec = ft_atoi(tmpatoi);
			tmp = (*list)->prec;
			while ((tmp /= 10) > 0)
				(*list)->pos += 1;
			(*list)->pos += 1;
		}
		if ((*list)->fs[(*list)->pos] == '*')
		{
			(*list)->prec = va_arg((*list)->args, int);
			(*list)->pos += 1;
		}
	}
}

void	ft_get_length(t_printf **list, int i)
{
	int		tmp;
	char	*tmpatoi;

	if (i == 0)
		if ((*list)->fs[(*list)->pos] >= '1'
				&& (*list)->fs[(*list)->pos] <= '9')
		{
			tmpatoi = &(*list)->fs[(*list)->pos];
			(*list)->width = ft_atoi(tmpatoi);
			tmp = (*list)->width;
			while ((tmp /= 10) > 0)
				(*list)->pos += 1;
			(*list)->pos += 1;
		}
	if (i == 1)
		if (ft_strchr("hlLjzt", (*list)->fs[(*list)->pos]))
		{
			(*list)->length = 1;
			(*list)->pos += 1;
			if (ft_strchr("hl", (*list)->fs[(*list)->pos]))
				(*list)->pos += 1;
		}
}

void	ft_get_specifier(t_printf **list)
{
	(*list)->fs[(*list)->pos] == 'c' ? (*list)->spe = 'c' : 0;
	(*list)->fs[(*list)->pos] == 's' ? (*list)->spe = 's' : 0;
	(*list)->fs[(*list)->pos] == 'p' ? (*list)->spe = 'p' : 0;
	(*list)->fs[(*list)->pos] == 'd' ? (*list)->spe = 'd' : 0;
	(*list)->fs[(*list)->pos] == 'i' ? (*list)->spe = 'i' : 0;
	(*list)->fs[(*list)->pos] == 'u' ? (*list)->spe = 'u' : 0;
	(*list)->fs[(*list)->pos] == 'x' ? (*list)->spe = 'x' : 0;
	(*list)->fs[(*list)->pos] == 'X' ? (*list)->spe = 'X' : 0;
	(*list)->fs[(*list)->pos] == '%' ? (*list)->spe = '%' : 0;
	(*list)->fs[(*list)->pos] == 'n' ? (*list)->spe = 'n' : 0;
	(*list)->fs[(*list)->pos] == 'f' ? (*list)->spe = 'f' : 0;
	(*list)->fs[(*list)->pos] == 'g' ? (*list)->spe = 'g' : 0;
	(*list)->fs[(*list)->pos] == 'e' ? (*list)->spe = 'e' : 0;
	(*list)->fs[(*list)->pos] == 'o' ? (*list)->spe = 'o' : 0;
	(*list)->fs[(*list)->pos] == 'E' ? (*list)->spe = 'E' : 0;
	(*list)->fs[(*list)->pos] == 'F' ? (*list)->spe = 'F' : 0;
	(*list)->fs[(*list)->pos] == 'G' ? (*list)->spe = 'G' : 0;
	(*list)->fs[(*list)->pos] == 'a' ? (*list)->spe = 'a' : 0;
	(*list)->fs[(*list)->pos] == 'A' ? (*list)->spe = 'A' : 0;
	(*list)->fs[(*list)->pos] == 'C' ? (*list)->spe = 'C' : 0;
	(*list)->fs[(*list)->pos] == 'S' ? (*list)->spe = 'S' : 0;
	(*list)->fs[(*list)->pos] == 'm' ? (*list)->spe = 'm' : 0;
	(*list)->pos += 1;
}
