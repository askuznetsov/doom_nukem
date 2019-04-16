/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_varible.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 19:54:10 by tvoronyu          #+#    #+#             */
/*   Updated: 2019/01/24 19:54:16 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init_varible(t_wolf *wolf)
{
	wolf->sdl.up = load_image("texture/ceil.jpg");
	wolf->sdl.floor = load_image("texture/floor.jpg");
	wolf->sdl.wall[0] = load_image("texture/11.jpg");
	wolf->sdl.wall[1] = load_image("texture/16.jpg");
	wolf->sdl.wall[2] = load_image("texture/13.jpg");
	wolf->sdl.wall[3] = load_image("texture/14.jpg");
	wolf->sdl.mus[0] = load_music("texture/sound.mp3");
	wolf->raycast.dir_x = 1.0;
	wolf->raycast.dir_y = 0.0;
	wolf->raycast.plan_x = 0.0;
	wolf->raycast.plan_y = -0.66;
	wolf->speed = 0.1;
	wolf->loop = 1;
	wolf->pause = 1;
	wolf->loop_shadow = 0;
	wolf->t1 = wolf->width_arr;
	wolf->t2 = wolf->height_arr;
}
