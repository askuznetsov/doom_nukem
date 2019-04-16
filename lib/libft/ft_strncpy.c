/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 13:04:06 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/03/28 13:33:42 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	char *s1;

	s1 = dest;
	while (len > 0 && *src != '\0')
	{
		*dest++ = *src++;
		len--;
	}
	while (len > 0)
	{
		*dest++ = '\0';
		len--;
	}
	return (s1);
}
