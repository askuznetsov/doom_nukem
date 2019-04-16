/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:37:55 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/04/05 10:15:39 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elem;

	if (!(elem = (t_list *)malloc(sizeof(t_list))))
		return (0);
	if (content == NULL || content_size == 0)
	{
		elem->content = NULL;
		elem->content_size = 0;
	}
	else
	{
		elem->content = ft_memcpy(ft_memalloc(content_size + 1),
				content, content_size);
		elem->content_size = content_size;
	}
	elem->next = NULL;
	return (elem);
}
