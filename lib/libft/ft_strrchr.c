/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 14:16:08 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/03/28 14:40:00 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int symbol)
{
	int len;

	len = ft_strlen((char*)str);
	while (len != 0 && str[len] != (char)symbol)
		len--;
	if (str[len] == (char)symbol)
		return ((char*)&str[len]);
	return (NULL);
}
