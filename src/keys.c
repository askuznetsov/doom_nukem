/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 19:30:34 by tvoronyu          #+#    #+#             */
/*   Updated: 2019/01/24 19:39:13 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_keys_2(t_wolf *wolf)
{
	if (wolf->keys[SDL_SCANCODE_LEFT])
	{
		wolf->dir = wolf->raycast.dir_x;
		wolf->raycast.dir_x = wolf->raycast.dir_x * cos(wolf->koef) -
			wolf->raycast.dir_y * sin(wolf->koef);
		wolf->raycast.dir_y = wolf->dir * sin(wolf->koef) +
			wolf->raycast.dir_y * cos(wolf->koef);
		wolf->plan = wolf->raycast.plan_x;
		wolf->raycast.plan_x = wolf->raycast.plan_x * cos(wolf->koef) -
			wolf->raycast.plan_y * sin(wolf->koef);
		wolf->raycast.plan_y = wolf->plan * sin(wolf->koef) +
			wolf->raycast.plan_y * cos(wolf->koef);
	}
	if (wolf->keys[SDL_SCANCODE_UP] || wolf->keys[SDL_SCANCODE_W])
	{
		if (wolf->array[(int)(wolf->raycast.pos_y)][(int)(wolf->raycast.pos_x
					+ wolf->raycast.dir_x * wolf->speed)] == 0)
			wolf->raycast.pos_x += wolf->raycast.dir_x * wolf->speed;
		if (wolf->array[(int)(wolf->raycast.pos_y + wolf->raycast.dir_y
					* wolf->speed)][(int)(wolf->raycast.pos_x)] == 0)
			wolf->raycast.pos_y += wolf->raycast.dir_y * wolf->speed;
	}
	if (wolf->keys[SDL_SCANCODE_T])
	{
		if (wolf->loop_shadow)
		{
			wolf->loop_shadow = 0;
			SDL_Delay(50);
		}
		else {
			wolf->loop_shadow = 1;
			SDL_Delay(50);
		}
	}
}

void	ft_keys_3(t_wolf *wolf)
{
	if (wolf->keys[SDL_SCANCODE_DOWN] || wolf->keys[SDL_SCANCODE_S])
	{
		if (wolf->array[(int)(wolf->raycast.pos_y)]
				[(int)(wolf->raycast.pos_x -
					wolf->raycast.dir_x * wolf->speed)] == 0)
			wolf->raycast.pos_x -= wolf->raycast.dir_x * wolf->speed;
		if (wolf->array
				[(int)(wolf->raycast.pos_y - wolf->raycast.dir_y * wolf->speed)]
				[(int)(wolf->raycast.pos_x)] == 0)
			wolf->raycast.pos_y -= wolf->raycast.dir_y * wolf->speed;
	}
	if (wolf->keys[SDL_SCANCODE_D])
	{
		if (wolf->array[(int)(wolf->raycast.pos_y +
					wolf->raycast.plan_y * wolf->speed)]
				[(int)(wolf->raycast.pos_x)] == 0)
			wolf->raycast.pos_y += wolf->raycast.plan_y *
					wolf->speed;
		if (wolf->array[(int)(wolf->raycast.pos_y)]
				[(int)(wolf->raycast.pos_x + wolf->raycast.plan_x *
					wolf->speed)] == 0)
			wolf->raycast.pos_x += wolf->raycast.plan_x *
				wolf->speed;
//				printf("%f\n", wolf->raycast.dir_x);
//				printf("%f\n", wolf->raycast.dir_y);
	}
}

void	ft_keys_4(t_wolf *wolf)
{
	if (wolf->keys[SDL_SCANCODE_A])
	{
		if (wolf->array[(int)(wolf->raycast.pos_y -
					wolf->raycast.plan_y * wolf->speed)]
				[(int)(wolf->raycast.pos_x)] == 0)
			wolf->raycast.pos_y -= wolf->raycast.plan_y * wolf->speed;
		if (wolf->array[(int)(wolf->raycast.pos_y)]
				[(int)(wolf->raycast.pos_x -
					wolf->raycast.plan_x * wolf->speed)] == 0)
			wolf->raycast.pos_x -= wolf->raycast.plan_x
				* wolf->speed;
	}
}

void	ft_keys_help(t_wolf *wolf)
{
	ft_keys_1(wolf);
	ft_keys_2(wolf);
	ft_keys_3(wolf);
	ft_keys_4(wolf);
}

void	keys(t_wolf *wolf)
{
	wolf->koef = 0.05;
	wolf->dir = 0.0;
	wolf->plan = 0.0;
	wolf->keys = SDL_GetKeyboardState(NULL);
	ft_pause_2(wolf);
	while (SDL_PollEvent(&wolf->sdl.event))
		if (wolf->pause)
			ft_move_left(wolf);
	if (wolf->pause)
		ft_keys_help(wolf);
	if (wolf->keys[SDL_SCANCODE_P])
	{
		if (wolf->pause)
		{
			SDL_Delay(100);
			wolf->pause = 0;
			SDL_SetRelativeMouseMode(0);
		}
		else
		{
			SDL_Delay(100);
			wolf->pause = 1;
			SDL_SetRelativeMouseMode(1);
		}
	}
}
