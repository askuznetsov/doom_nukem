/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 19:39:30 by tvoronyu          #+#    #+#             */
/*   Updated: 2019/01/24 19:46:27 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_mouse_right(t_wolf *wolf)
{
	if (wolf->sdl.event.motion.xrel > 0 && wolf->sdl.event.motion.xrel < 1000)
	{
		wolf->dir = wolf->raycast.dir_x;
		wolf->raycast.dir_x = wolf->raycast.dir_x *
			cos(-(fabs(wolf->sdl.event.motion.xrel / 700.0))) -
			wolf->raycast.dir_y *
			sin(-(fabs(wolf->sdl.event.motion.xrel / 700.0)));
		wolf->raycast.dir_y = wolf->dir *
			sin(-(fabs(wolf->sdl.event.motion.xrel / 700.0))) +
			wolf->raycast.dir_y *
			cos(-(fabs(wolf->sdl.event.motion.xrel / 700.0)));
		wolf->plan = wolf->raycast.plan_x;
		wolf->raycast.plan_x = wolf->raycast.plan_x *
			cos(-(fabs(wolf->sdl.event.motion.xrel / 700.0))) -
			wolf->raycast.plan_y *
			sin(-(fabs(wolf->sdl.event.motion.xrel / 700.0)));
		wolf->raycast.plan_y = wolf->plan *
			sin(-(fabs(wolf->sdl.event.motion.xrel / 700.0))) +
			wolf->raycast.plan_y *
			cos(-(fabs(wolf->sdl.event.motion.xrel / 700.0)));
	}
}

void	ft_move_left(t_wolf *wolf)
{
	if (wolf->sdl.event.motion.xrel > -1000 && wolf->sdl.event.motion.xrel < 0)
	{
		wolf->dir = wolf->raycast.dir_x;
		wolf->raycast.dir_x = wolf->raycast.dir_x *
			cos(fabs(wolf->sdl.event.motion.xrel / 700.0)) -
			wolf->raycast.dir_y *
			sin(fabs(wolf->sdl.event.motion.xrel / 700.0));
		wolf->raycast.dir_y = wolf->dir *
			sin(fabs(wolf->sdl.event.motion.xrel / 700.0)) +
			wolf->raycast.dir_y *
			cos(fabs(wolf->sdl.event.motion.xrel / 700.0));
		wolf->plan = wolf->raycast.plan_x;
		wolf->raycast.plan_x = wolf->raycast.plan_x *
			cos(fabs(wolf->sdl.event.motion.xrel / 700.0)) -
			wolf->raycast.plan_y *
			sin(fabs(wolf->sdl.event.motion.xrel / 700.0));
		wolf->raycast.plan_y = wolf->plan *
			sin(fabs(wolf->sdl.event.motion.xrel / 700.0)) +
			wolf->raycast.plan_y *
			cos(fabs(wolf->sdl.event.motion.xrel / 700.0));
	}
	ft_mouse_right(wolf);
}

void	ft_pause_2(t_wolf *wolf)
{
	if (wolf->sdl.event.type == SDL_QUIT
			|| (wolf->sdl.event.key.keysym.sym == SDLK_ESCAPE))
		wolf->loop = 0;
}

void	ft_keys_1(t_wolf *wolf)
{
	if (wolf->keys[SDL_SCANCODE_LSHIFT] == 1)
		wolf->speed = 0.15;
	else
	{
		if (wolf->keys[SDL_SCANCODE_LALT] == 1)
			wolf->speed = 0.04;
		else
			wolf->speed = 0.075;
	}
	if (wolf->keys[SDL_SCANCODE_RIGHT])
	{
		wolf->dir = wolf->raycast.dir_x;
		wolf->raycast.dir_x = wolf->raycast.dir_x *
			cos(-wolf->koef) - wolf->raycast.dir_y * sin(-wolf->koef);
		wolf->raycast.dir_y = wolf->dir * sin(-wolf->koef)
			+ wolf->raycast.dir_y * cos(-wolf->koef);
		wolf->plan = wolf->raycast.plan_x;
		wolf->raycast.plan_x = wolf->raycast.plan_x *
			cos(-wolf->koef) - wolf->raycast.plan_y * sin(-wolf->koef);
		wolf->raycast.plan_y = wolf->plan * sin(-wolf->koef) +
			wolf->raycast.plan_y * cos(-wolf->koef);
	}
}
