/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 13:38:37 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/03/31 13:08:33 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memptr, int val, size_t num)
{
	unsigned char *strmemptr;

	strmemptr = (unsigned char*)memptr;
	while (num > 0 && *strmemptr != (unsigned char)val)
	{
		num--;
		strmemptr++;
	}
	if (num == 0)
		return (NULL);
	else
		return ((void*)strmemptr);
}
