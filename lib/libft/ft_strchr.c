/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 13:57:19 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/03/28 14:33:59 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int symbol)
{
	while (*str != '\0' && *str != (char)symbol)
		str++;
	if (*str == (char)symbol)
		return ((char*)str);
	return (NULL);
}
