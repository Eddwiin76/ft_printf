/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:55:58 by tpierre           #+#    #+#             */
/*   Updated: 2020/03/13 04:08:33 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_parser(const char *format, t_printf **list)
{
	int i;

	(*list)->rang += 1;
	i = (*list)->rang;
	while (!(ft_strchr("cspdiuxX%nfgeoEFGaACSm", format[(*list)->rang])))
		(*list)->rang += 1;
	(*list)->fs = ft_substr(format, i, ((*list)->rang - i + 1));
	ft_get_flag(list);
	if (!ft_strchr("cspdiuxX%nfgeoEFGaACSm", (*list)->fs[(*list)->pos]))
	{
		ft_get_width(list);
		if ((*list)->dot == 1)
			ft_get_prec(list);
		ft_get_length(list, 1);
	}
	ft_get_specifier(list);
}

int		ft_verif(t_printf **list)
{
	if ((*list)->width < 0)
	{
		(*list)->width *= -1;
		(*list)->minus = 1;
	}
	if ((*list)->prec < 0)
		(*list)->dot = 0;
	if ((*list)->zero == 1 && (*list)->width == 0)
		(*list)->zero = 0;
	if ((*list)->zero == 1 && (*list)->minus == 1)
		(*list)->zero = 0;
	return (1);
}

void	ft_parcer_specifier(t_printf **list)
{
	(*list)->spe == 'c' ? ft_flag_char(list) : 0;
	(*list)->spe == 's' ? ft_flag_str(list) : 0;
	(*list)->spe == 'p' ? ft_flag_adr(list) : 0;
	(*list)->spe == 'd' ? ft_flag_int(list) : 0;
	(*list)->spe == 'i' ? ft_flag_int(list) : 0;
	(*list)->spe == 'u' ? ft_flag_uint(list) : 0;
	(*list)->spe == 'x' ? ft_flag_hexa(list) : 0;
	(*list)->spe == 'X' ? ft_flag_uhexa(list) : 0;
	(*list)->spe == '%' ? ft_flag_per(list) : 0;
}
