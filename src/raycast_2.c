/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 19:59:29 by tvoronyu          #+#    #+#             */
/*   Updated: 2019/01/24 20:03:02 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_check_side_and_step(t_wolf *wolf)
{
	if (wolf->raycast.ray_dir_x < 0)
	{
		wolf->raycast.step_x = -1;
		wolf->raycast.side_dist_x = (wolf->raycast.pos_x -
				wolf->raycast.map_x) * wolf->raycast.delta_dist_x;
	}
	else
	{
		wolf->raycast.step_x = 1;
		wolf->raycast.side_dist_x = (wolf->raycast.map_x +
				1.0 - wolf->raycast.pos_x) * wolf->raycast.delta_dist_x;
	}
	ft_check_side_and_step_help(wolf);
}

void	ft_check_wall(t_wolf *wolf)
{
	while (wolf->raycast.hit == 0)
	{
		if (wolf->raycast.side_dist_x < wolf->raycast.side_dist_y)
		{
			wolf->raycast.side_dist_x += wolf->raycast.delta_dist_x;
			wolf->raycast.map_x += wolf->raycast.step_x;
			wolf->raycast.side = 0;
		}
		else
		{
			wolf->raycast.side_dist_y += wolf->raycast.delta_dist_y;
			wolf->raycast.map_y += wolf->raycast.step_y;
			wolf->raycast.side = 1;
		}
		if (wolf->array[wolf->raycast.map_y][wolf->raycast.map_x] > 0)
			wolf->raycast.hit = 1;
	}
}

void	ft_check_wall_dist(t_wolf *wolf)
{
	if (wolf->raycast.side == 0)
		wolf->draw.perp_wall_dist = (wolf->raycast.map_x - wolf->raycast.pos_x
				+ (1 - wolf->raycast.step_x) / 2) / wolf->raycast.ray_dir_x;
	else
		wolf->draw.perp_wall_dist = (wolf->raycast.map_y - wolf->raycast.pos_y
				+ (1 - wolf->raycast.step_y) / 2) / wolf->raycast.ray_dir_y;
	wolf->draw.line_height = (int)(HEIGHT / wolf->draw.perp_wall_dist);
	wolf->draw.draw_start = (-wolf->draw.line_height / 2 + HEIGHT / 2);
}

void	ft_start_end(t_wolf *wolf)
{
	if (wolf->draw.draw_start < 0)
		wolf->draw.draw_start = 0;
	wolf->draw.draw_end = (wolf->draw.line_height / 2 + HEIGHT / 2);
	if (wolf->draw.draw_end >= HEIGHT)
		wolf->draw.draw_end = HEIGHT - 1;
}

int		ft_select_wall(t_wolf *wolf)
{
	int n;

	n = wolf->array[wolf->raycast.map_y][wolf->raycast.map_x] - 1;
	if (wolf->raycast.side == 0)
	{
		if (wolf->raycast.ray_dir_x > 0)
			n = 0;
		else
			n = 1;
	}
	else
	{
		if (wolf->raycast.ray_dir_y > 0)
			n = 2;
		else
			n = 3;
	}
	return (n);
}
