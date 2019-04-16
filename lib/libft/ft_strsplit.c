/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:40:16 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/04/03 13:05:45 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				**ft_strsplit(char const *s, char c)
{
	char		**ret;
	int			i;
	const char	*next;

	if (s == 0)
		return (0);
	ret = (char**)malloc(sizeof(char*) * (ft_strcount(s, c) + 1));
	if (ret == 0)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		s = ft_str_index_next(s, c, 1);
		if (*s != '\0')
		{
			next = ft_str_index_next(s, c, 0);
			ret[i] = ft_strsub(s, 0, next - s);
			if (ret[i] == 0)
				return (ft_free(ret, i));
			i++;
			s = next;
		}
	}
	ret[i] = 0;
	return (ret);
}
