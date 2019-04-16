/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 19:54:44 by tvoronyu          #+#    #+#             */
/*   Updated: 2019/01/24 19:59:02 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_calc_wall(t_wolf *wolf)
{
	if (wolf->raycast.side == 0)
		wolf->draw.wall_x = wolf->raycast.pos_y
			+ wolf->draw.perp_wall_dist * wolf->raycast.ray_dir_y;
	else
		wolf->draw.wall_x = wolf->raycast.pos_x
			+ wolf->draw.perp_wall_dist * wolf->raycast.ray_dir_x;
	wolf->draw.wall_x -= floor(wolf->draw.wall_x);
	wolf->draw.tex_x = (int)(wolf->draw.wall_x * 256.0);
	if (wolf->raycast.side == 0 && wolf->raycast.ray_dir_x > 0)
		wolf->draw.tex_x = 256.0 - wolf->draw.tex_x - 1;
	if (wolf->raycast.side == 1 & wolf->raycast.ray_dir_y < 0)
		wolf->draw.tex_x = 256.0 - wolf->draw.tex_x - 1;
	wolf->y = wolf->draw.draw_start;
}

void	ft_init_floor_ceil(t_wolf *wolf)
{
	if (wolf->raycast.side == 0 && wolf->raycast.ray_dir_x > 0)
	{
		wolf->draw.floor_wall_x = wolf->raycast.map_x;
		wolf->draw.floor_wall_y = wolf->raycast.map_y + wolf->draw.wall_x;
	}
	else if (wolf->raycast.side == 0 && wolf->raycast.ray_dir_x < 0)
	{
		wolf->draw.floor_wall_x = wolf->raycast.map_x + 1.0;
		wolf->draw.floor_wall_y = wolf->raycast.map_y + wolf->draw.wall_x;
	}
	else if (wolf->raycast.side == 1 && wolf->raycast.ray_dir_y > 0)
	{
		wolf->draw.floor_wall_x = wolf->raycast.map_x + wolf->draw.wall_x;
		wolf->draw.floor_wall_y = wolf->raycast.map_y;
	}
	else
	{
		wolf->draw.floor_wall_x = wolf->raycast.map_x + wolf->draw.wall_x;
		wolf->draw.floor_wall_y = wolf->raycast.map_y + 1.0;
	}
}

void	ft_floor_ceil_help(t_wolf *wolf, unsigned int *color)
{
    int r;
    int g;
    int b;

	if (wolf->draw.draw_end < 0)
		wolf->draw.draw_end = HEIGHT;
	wolf->y = wolf->draw.draw_end - 1;
	while (++wolf->y < HEIGHT)
	{
		wolf->draw.current_dist = HEIGHT / (2.0 * wolf->y - HEIGHT);
		wolf->draw.weight = (wolf->draw.current_dist -
				wolf->raycast.dist_player)
			/ (wolf->draw.perp_wall_dist - wolf->raycast.dist_player);
		wolf->draw.current_floor_x = wolf->draw.weight * wolf->draw.floor_wall_x
			+ (1.0 - wolf->draw.weight) * wolf->raycast.pos_x;
		wolf->draw.current_floor_y = wolf->draw.weight * wolf->draw.floor_wall_y
			+ (1.0 - wolf->draw.weight) * wolf->raycast.pos_y;
		wolf->draw.floor_tex_x = (int)(wolf->draw.current_floor_x * 256) % 256;
		wolf->draw.floor_tex_y = (int)(wolf->draw.current_floor_y * 256) % 256;
		*color = get_pixel_int(wolf->sdl.floor,
				wolf->draw.floor_tex_x, wolf->draw.floor_tex_y);
		if (wolf->loop_shadow)
        if (wolf->draw.current_dist > 0.99) {
            r = ((*color >> 16) & 255) / wolf->draw.current_dist;
            g = ((*color >> 8) & 255) / wolf->draw.current_dist;
            b = ((*color & 255) / wolf->draw.current_dist);
            *color = (256 * 256 * r) + (256 * g) + b;
        }
		wolf->buf[wolf->y][wolf->x] = *color;
		*color = get_pixel_int(wolf->sdl.up,
				wolf->draw.floor_tex_x, wolf->draw.floor_tex_y);
		if (wolf->loop_shadow)
		if (wolf->draw.current_dist > 0.99) {
			r = ((*color >> 16) & 255) / wolf->draw.current_dist;
			g = ((*color >> 8) & 255) / wolf->draw.current_dist;
			b = ((*color & 255) / wolf->draw.current_dist);
			*color = (256 * 256 * r) + (256 * g) + b;
		}
		wolf->buf[WIDTH / 4 * 3 - wolf->y][wolf->x] = *color;
	}
}

void	render(t_wolf *wolf)
{
	int				n;
	unsigned int	color;
	int r;
	int g;
	int b;

	ft_init_raycast(wolf);
	ft_check_side_and_step(wolf);
	ft_check_wall(wolf);
	ft_check_wall_dist(wolf);
	ft_start_end(wolf);
	n = ft_select_wall(wolf);
	ft_calc_wall(wolf);
	while (++wolf->y < wolf->draw.draw_end)
	{
		wolf->d = wolf->y * 256 - HEIGHT * 128 + wolf->draw.line_height * 128;
		wolf->draw.tex_y = ((wolf->d * 256.0) / wolf->draw.line_height / 256);
		if ((color = get_pixel_int(wolf->sdl.wall[n],
						wolf->draw.tex_x, wolf->draw.tex_y)) != 0) {
			if (wolf->loop_shadow)
            if (wolf->draw.perp_wall_dist > 0.99) {
                r = ((color >> 16) & 255) / (wolf->draw.perp_wall_dist);
                g = ((color >> 8) & 255) / (wolf->draw.perp_wall_dist);
                b = ((color & 255) / (wolf->draw.perp_wall_dist));
                color = (256 * 256 * r) + (256 * g) + b;
            }
            wolf->buf[wolf->y][wolf->x] = color;
        }
	}
	ft_init_floor_ceil(wolf);
	ft_floor_ceil_help(wolf, &color);
}

void	ft_init_raycast(t_wolf *wolf)
{
	wolf->raycast.camera_x = (double)((wolf->x * 2) / (double)(WIDTH) - 1);
	wolf->raycast.ray_dir_x = wolf->raycast.dir_x
		+ wolf->raycast.plan_x * wolf->raycast.camera_x;
	wolf->raycast.ray_dir_y = wolf->raycast.dir_y
		+ wolf->raycast.plan_y * wolf->raycast.camera_x;
	if ((int)wolf->raycast.pos_x > wolf->width_arr)
		wolf->raycast.pos_x = wolf->width_arr;
	if ((int)wolf->raycast.pos_y > wolf->height_arr)
		wolf->raycast.pos_y = wolf->height_arr;
	wolf->raycast.map_x = (int)wolf->raycast.pos_x;
	wolf->raycast.map_y = (int)wolf->raycast.pos_y;
	wolf->raycast.delta_dist_x = fabs(1 / wolf->raycast.ray_dir_x);
	wolf->raycast.delta_dist_y = fabs(1 / wolf->raycast.ray_dir_y);
	wolf->raycast.hit = 0;
}
