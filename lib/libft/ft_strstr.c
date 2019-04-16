/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 14:45:05 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/03/27 10:19:17 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	const char *s1;
	const char *s2;

	if (*str2 == '\0')
		return ((char*)str1);
	while (*str1 != '\0')
	{
		s1 = str1;
		s2 = str2;
		while (*s2 != '\0' && *s2 == *s1)
		{
			s2++;
			s1++;
		}
		if (*s2 == '\0')
			return ((char*)str1);
		str1++;
	}
	return (0);
}
