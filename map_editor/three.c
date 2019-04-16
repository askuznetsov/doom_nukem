/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <okuznets@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 20:44:53 by okuznets          #+#    #+#             */
/*   Updated: 2019/04/16 21:12:45 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

void	sdl_boot(t_general *general)
{
	t_tools temp;

	temp.x = -1;
	bzero(general->text, 9);//to write bzero
	general->map = (unsigned int*)malloc(general->mode * sizeof(unsigned int*));
	while (++temp.x < general->mode)
	{
		general->map[temp.x] = (unsigned int*)malloc(general->mode * sizeof(unsigned int));
		temp.y = -1;
	}
}
