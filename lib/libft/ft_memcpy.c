/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 12:40:28 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/03/25 16:59:54 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	char		*strdest;
	const char	*strsrc;

	strdest = (char*)dest;
	strsrc = (const char*)src;
	while (num--)
		*strdest++ = *strsrc++;
	return (dest);
}
