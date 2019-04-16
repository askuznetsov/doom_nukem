/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 19:50:22 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/04/04 19:50:56 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr2(const char *str1, const char *str2, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (str1[i] != '\0' && i < len)
	{
		if (str1[i] == str2[j])
		{
			while (str1[i + j] == str2[j] && str1[i + j]
					&& str2[j] && i + j < len)
			{
				if (j == ft_strlen(str2) - 1)
					return ((char*)str1 + i);
				j++;
			}
		}
		i++;
		j = 0;
	}
	return (NULL);
}
