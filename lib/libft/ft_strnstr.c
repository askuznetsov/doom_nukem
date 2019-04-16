/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 23:02:26 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/04/04 19:34:57 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *haystack,
		const char *needle, size_t len)
{
	if (!ft_strlen(needle))
		return ((char*)haystack);
	else
	{
		return (ft_strnstr2(haystack, needle, len));
	}
}
