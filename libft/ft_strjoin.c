/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:09:12 by tpierre           #+#    #+#             */
/*   Updated: 2020/03/10 18:54:42 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lens1ands2;
	char	*dst;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens1ands2 = ft_strlen(s1) + ft_strlen(s2);
	if (!(dst = (char *)malloc(sizeof(char) * (lens1ands2 + 1))))
		return (NULL);
	ft_bzero(dst, lens1ands2 + 1);
	dst = ft_strcat(dst, s1);
	dst = ft_strcat(dst, s2);
	return (dst);
}
