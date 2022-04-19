/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:57:35 by tpierre           #+#    #+#             */
/*   Updated: 2020/03/13 08:49:10 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *format, ...)
{
	t_printf *list;

	if (!(list = (t_printf *)malloc(sizeof(t_printf))))
		return (-1);
	ft_initialyze(&list);
	va_start(list->args, format);
	while (format[list->rang])
	{
		if (format[list->rang] == '%')
		{
			ft_parser(format, &list);
			if (ft_verif(&list) == -1)
				return (0);
			ft_parcer_specifier(&list);
		}
		else
			list->nprinted +=
					ft_putchar_printf_fd((char)format[list->rang], 1);
		list->rang += 1;
		ft_reinitialyze(&list);
	}
	va_end(list->args);
	free(list);
	return (list->nprinted);
}
