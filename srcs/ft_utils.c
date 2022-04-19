/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:54:31 by tpierre           #+#    #+#             */
/*   Updated: 2020/03/13 04:29:18 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_putchar_space_fd(int nb, int fd)
{
	int i;

	i = -1;
	while (++i < nb)
		ft_putchar_fd(' ', fd);
	return (nb);
}

int		ft_putchar_zero_fd(int nb, int fd)
{
	int i;

	i = -1;
	while (++i < nb)
		ft_putchar_fd('0', fd);
	return (nb);
}

int		ft_putchar_nstr_fd(char *str, int n, int fd)
{
	int i;

	i = -1;
	while (++i < n)
		ft_putchar_fd(str[i], fd);
	return (n);
}

int		ft_putchar_printf_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
