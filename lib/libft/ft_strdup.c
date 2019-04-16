/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 14:34:44 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/03/26 12:33:43 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int		index;

	if (!(str = (char*)malloc(sizeof(*str) * (ft_strlen(src) + 1))))
		return (NULL);
	index = 0;
	while (src[index] != '\0')
	{
		str[index] = src[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}
