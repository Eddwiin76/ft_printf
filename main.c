/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 06:27:45 by tpierre           #+#    #+#             */
/*   Updated: 2020/03/13 08:52:48 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/printf.h"
#include <limits.h>

int	main()
{
//	printf("%*.52s%.d%07.*X%25c\n", -42, "INT_MIN", 6541, 58, 12585, 104);
	ft_printf("%*.52s%.d%07.*X%25c\n", -42, "INT_MIN", 6541, 58, 12585, 104);
//	ft_printf("%s\n", "yolo");
//	ft_printf("otu");
	system("leaks a.out");

	//ft_printf("%*.52s\n", -42, "INT_MIN");
}
