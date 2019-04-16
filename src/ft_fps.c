/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 19:10:22 by tvoronyu          #+#    #+#             */
/*   Updated: 2019/01/24 20:22:05 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_fps(t_wolf *wolf)
{
	static int		my_time;
	static int		fps;
	static int		my_fps;
	char			*s;

	if (time(NULL) != my_time)
	{
		my_fps = fps;
		fps = 0;
		my_time = (int)time(NULL);
	}
	else
		fps++;
	s = ft_itoa(my_fps);
	wolf->test = ft_strjoin("FPS ", s);
	free(s);
}

void	ft_init_ttf(t_wolf *wolf)
{
	SDL_Color color;

	color.r = 255;
	color.g = 255;
	color.b = 255;
	if (!(wolf->sdl.font_ttf = TTF_OpenFont("Roboto-Bold.ttf", 20)))
		ft_error(1, wolf);
	SDL_GetWindowSize(wolf->sdl.win, &wolf->ww, &wolf->wh);
	wolf->sdl.font_surface = TTF_RenderText_Solid(wolf->sdl.font_ttf,
			wolf->test, color);
	wolf->sdl.font_text = SDL_CreateTextureFromSurface(wolf->sdl.ren,
			wolf->sdl.font_surface);
	SDL_QueryTexture(wolf->sdl.font_text, NULL, NULL,
			&wolf->tw, &wolf->th);
	wolf->sdl.font_rect.x = wolf->ww - 100;
	wolf->sdl.font_rect.y = wolf->wh - 40;
	wolf->sdl.font_rect.w = wolf->tw;
	wolf->sdl.font_rect.h = wolf->th;
}
