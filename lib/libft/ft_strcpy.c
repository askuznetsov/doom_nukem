/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 15:33:31 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/03/26 12:37:43 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char	*str;
	int		index;

	str = dst;
	index = 0;
	while (*src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (str);
}
