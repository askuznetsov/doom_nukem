/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 10:29:45 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/03/27 12:50:15 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *array;

	array = malloc(size);
	if (array == NULL)
		return (NULL);
	return (array = ft_memset(array, 0, size));
}
