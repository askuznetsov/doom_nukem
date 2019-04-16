/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:11:06 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/03/26 14:55:33 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *str1;
	unsigned char *str2;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	if (n <= 0)
		return (0);
	while (*str1 == *str2 && *str1 != '\0' && *str2 != '\0' && n-- > 1)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
