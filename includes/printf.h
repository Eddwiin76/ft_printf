/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:45:22 by tpierre           #+#    #+#             */
/*   Updated: 2020/03/13 04:55:06 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_printf
{
	va_list		args;
	int			len;
	char		*fs;
	int			rang;
	int			pos;
	int			width;
	int			prec;
	int			length;
	int			nprinted;
	int			dot;
	int			minus;
	int			minusprec;
	int			zero;
	int			star;
	int			hash;
	int			space;
	int			plus;
	char		spe;
}				t_printf;

int				ft_printf(const char *format, ...);
void			ft_initialyze(t_printf **list);
void			ft_reinitialyze(t_printf **list);
void			ft_parser(const char *format, t_printf **list);
void			ft_get_flag(t_printf **list);
void			ft_get_width(t_printf **list);
void			ft_get_prec(t_printf **list);
void			ft_get_length(t_printf **list, int i);
void			ft_get_specifier(t_printf **list);
void			ft_parcer_specifier(t_printf **list);
int				ft_verif(t_printf **list);
void			ft_flag_char(t_printf **list);
void			ft_flag_str(t_printf **list);
void			ft_flag_adr(t_printf **list);
void			ft_flag_int(t_printf **list);
void			ft_flag_uint(t_printf **list);
void			ft_flag_hexa(t_printf **list);
void			ft_flag_uhexa(t_printf **list);
void			ft_flag_per(t_printf **list);

int				ft_putchar_zero_fd(int nb, int fd);
int				ft_putchar_space_fd(int nb, int fd);
int				ft_putchar_nstr_fd(char *str, int n, int fd);
int				ft_putchar_printf_fd(char c, int fd);

void			ft_printf_list(t_printf **list);

#endif
