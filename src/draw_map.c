/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 19:00:05 by tvoronyu          #+#    #+#             */
/*   Updated: 2019/01/24 19:10:08 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_draw_player(t_wolf *wolf)
{
	if ((int)((wolf->q / 6) - 1) >= 0)
		if ((int)((wolf->w / 6) - 1) >= 0)
			if (wolf->array[(int)((wolf->q / 6) - 1)]
					[(int)((wolf->w / 6) - 1)] != 0)
			{
				while (wolf->q < wolf->i + 6)
				{
					wolf->w = wolf->m;
					while (wolf->w < wolf->m + 6)
					{
						wolf->buf[(int)((wolf->i / 6) - 1)
							* 6 + abs(wolf->i - wolf->q)]
							[(int)((wolf->m / 6) - 1) * 6 +
							abs(wolf->m - wolf->w)] =
								(256 * 256 * 200) + (256 * 200) + 50;
						wolf->w++;
					}
					wolf->q++;
				}
			}
}

void	ft_draw_wall_help(t_wolf *wolf)
{
	while (wolf->q < wolf->i + 6)
	{
		wolf->w = wolf->m;
		while (wolf->w < wolf->m + 6)
		{
			wolf->buf[(int)wolf->raycast.pos_y
				* 6 + abs(wolf->i - wolf->q)]
				[(int)wolf->raycast.pos_x * 6
				+ abs(wolf->m - wolf->w)] = (256 *
						256 * 255) + (256 * 0) + 0;
			wolf->w++;
		}
		wolf->q++;
	}
}

void	ft_draw_wall(t_wolf *wolf)
{
	while (wolf->i++ < wolf->height_arr * 6)
	{
		wolf->m = -1;
		while (wolf->m++ < wolf->width_arr * 6)
		{
			wolf->buf[wolf->i][wolf->m] = (256 * 256 * 0) + (256 * 0) + 0;
			wolf->q = wolf->i;
			wolf->w = wolf->m;
			ft_draw_wall_help(wolf);
			wolf->q = wolf->i;
			wolf->w = wolf->m;
			ft_draw_player(wolf);
		}
	}
}

void	render_texture(t_wolf *wolf)
{
	SDL_UpdateTexture(wolf->sdl.screen, NULL, wolf->buf, WIDTH << 2);
	SDL_RenderCopy(wolf->sdl.ren, wolf->sdl.screen, NULL, NULL);
	SDL_RenderCopy(wolf->sdl.ren,
			wolf->sdl.font_text, NULL, &wolf->sdl.font_rect);
	SDL_RenderPresent(wolf->sdl.ren);
	SDL_DestroyTexture(wolf->sdl.font_text);
	SDL_FreeSurface(wolf->sdl.font_surface);
	TTF_CloseFont(wolf->sdl.font_ttf);
	free(wolf->test);
}
