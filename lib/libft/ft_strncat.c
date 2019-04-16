/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 13:20:13 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/03/26 12:45:42 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t num)
{
	char *s1;

	s1 = dest;
	while (*dest != '\0')
		dest++;
	while (*src != '\0' && num > 0)
	{
		*dest++ = *src++;
		num--;
	}
	*dest = '\0';
	return (s1);
}
