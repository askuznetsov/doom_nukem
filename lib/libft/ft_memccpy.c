/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 12:51:20 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/04/05 09:05:15 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t size)
{
	int				i;
	unsigned char	*strsrc;
	unsigned char	*strdest;

	i = 0;
	strsrc = (unsigned char *)src;
	strdest = (unsigned char *)dest;
	while (size--)
	{
		strdest[i] = strsrc[i];
		if (strsrc[i] == (unsigned char)c)
			return (strdest + i + 1);
		i++;
	}
	return (NULL);
}
