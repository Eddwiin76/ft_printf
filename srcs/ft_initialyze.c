/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialyze.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:22:22 by tpierre           #+#    #+#             */
/*   Updated: 2020/03/13 08:46:04 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_initialyze(t_printf **list)
{
	(*list)->len = 1;
	(*list)->fs = NULL;
	(*list)->pos = 0;
	(*list)->rang = 0;
	(*list)->width = 0;
	(*list)->prec = 0;
	(*list)->length = 0;
	(*list)->nprinted = 0;
	(*list)->dot = 0;
	(*list)->minus = 0;
	(*list)->minusprec = 0;
	(*list)->zero = 0;
	(*list)->star = 0;
	(*list)->hash = 0;
	(*list)->space = 0;
	(*list)->plus = 0;
	(*list)->spe = '0';
}

void	ft_reinitialyze(t_printf **list)
{
	free((*list)->fs);
	(*list)->len = 1;
	(*list)->fs = NULL;
	(*list)->pos = 0;
	(*list)->width = 0;
	(*list)->prec = 0;
	(*list)->length = 0;
	(*list)->dot = 0;
	(*list)->minus = 0;
	(*list)->minusprec = 0;
	(*list)->zero = 0;
	(*list)->star = 0;
	(*list)->hash = 0;
	(*list)->space = 0;
	(*list)->plus = 0;
	(*list)->spe = '0';
}
