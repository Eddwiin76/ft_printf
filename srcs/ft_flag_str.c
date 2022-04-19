/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:21:08 by tpierre           #+#    #+#             */
/*   Updated: 2020/03/12 16:14:12 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_flag_str(t_printf **list)
{
	char	*toprint;
	int		len;

	toprint = (char *)va_arg((*list)->args, char*);
	if (toprint == NULL)
		toprint = "(null)";
	if ((*list)->prec > 0 && (*list)->prec < (int)ft_strlen(toprint))
		len = (*list)->prec;
	else if ((*list)->dot == 1 && (*list)->prec == 0)
		len = 0;
	else
		len = ft_strlen(toprint);
	if ((*list)->minus == 0)
	{
		if ((*list)->width > len && (*list)->zero == 0)
			(*list)->nprinted += ft_putchar_space_fd((*list)->width - len, 1);
		else if ((*list)->width > len && (*list)->zero == 1)
			(*list)->nprinted += ft_putchar_zero_fd((*list)->width - len, 1);
	}
	(*list)->nprinted += ft_putchar_nstr_fd(toprint, len, 1);
	if ((*list)->minus == 1)
		if ((*list)->width > len)
			(*list)->nprinted += ft_putchar_space_fd((*list)->width - len, 1);
}
