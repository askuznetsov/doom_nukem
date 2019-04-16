/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 13:58:38 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/03/28 13:27:29 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *memptr1, const void *memptr2, size_t num)
{
	unsigned char	*strptr1;
	unsigned char	*strptr2;

	strptr1 = (unsigned char*)memptr1;
	strptr2 = (unsigned char*)memptr2;
	while (num > 0 && *strptr1 == *strptr2)
	{
		strptr1++;
		strptr2++;
		num--;
	}
	if (num == 0)
		return (0);
	return (*strptr1 - *strptr2);
}
