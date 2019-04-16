/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <okuznets@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 21:28:18 by okuznets          #+#    #+#             */
/*   Updated: 2019/04/16 20:44:25 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

void	general_setting(t_general *general)
{
	if (general->mode == 10)
	{
		general->xmode = 120;
		general->ymode = 80;
	}
	else
	{
		general->xmode = 24;
		general->ymode = 16;
	}
}

void	words_loose(char **words)
{
	int count;

	count = 0;
	while (words[count])
	{
		free(words[count]);
		count++;
	}
	free(words);
	words = NULL;
}

int		words_width(char **coords)
{
	int count;

	count = 0;
	while(*coords)
	{
		coords++;
		count++;
	}
	return (count);
}

void	headpush(t_solidus **front, t_solidus *global)
{
	t_solidus *temp;

	temp = malloc(sizeof(t_solidus));
	temp->x1 = global->x1;
	temp->x2 = global->x2;
	temp->y1 = global->y1;
	temp->y2 = global->y2;
	temp->height = global->height;
	temp->texture_number = global->texture_number;
	temp->text = *front;
	*front = temp;
}
