/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:00:15 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/03/25 16:44:34 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	char *temp;

	if (n <= 0)
		return (dest);
	temp = (char *)dest;
	while (n--)
		*temp++ = c;
	return (dest);
}
