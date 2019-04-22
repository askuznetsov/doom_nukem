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

void	ft_bzero(void *s, size_t n)
{
    int		i;
    char	*str;

    i = 0;
    str = (char*)s;
    while (n--)
    {
        str[i] = '\0';
        i++;
    }
}

void    tex_join2(t_general *general)
{
    general->texture[10] = IMG_LoadTexture(global->renderer, "../texture/texture_10.png");
    general->texture[11] = IMG_LoadTexture(global->renderer, "../texture/texture_11.png");
    general->texture[12] = IMG_LoadTexture(global->renderer, "../texture/texture_12.png");
    general->texture[13] = IMG_LoadTexture(global->renderer, "../texture/texture_13.png");
    general->texture[14] = IMG_LoadTexture(global->renderer, "../texture/texture_14.png");
    general->texture[15] = IMG_LoadTexture(global->renderer, "../texture/texture_15.png");
}

void    tex_join(t_general *general)
{
    general->texture[0] = IMG_LoadTexture(global->renderer, "../texture/texture_0.png");
    general->texture[1] = IMG_LoadTexture(global->renderer, "../texture/texture_1.png");
    general->texture[2] = IMG_LoadTexture(global->renderer, "../texture/texture_2.png");
    general->texture[3] = IMG_LoadTexture(global->renderer, "../texture/texture_3.png");
    general->texture[4] = IMG_LoadTexture(global->renderer, "../texture/texture_4.png");
    general->texture[5] = IMG_LoadTexture(global->renderer, "../texture/texture_5.png");
    general->texture[6] = IMG_LoadTexture(global->renderer, "../texture/texture_6.png");
    general->texture[7] = IMG_LoadTexture(global->renderer, "../texture/texture_7.png");
    general->texture[8] = IMG_LoadTexture(global->renderer, "../texture/texture_8.png");
    general->texture[9] = IMG_LoadTexture(global->renderer, "../texture/texture_9.png");
    tex_join2(general);
}

void	sdl_boot(t_general *general)
{
	t_tools temp;

	temp.x = -1;
	ft_bzero(general->text, 9);
	general->map = (unsigned int*)malloc(general->mode * sizeof(unsigned int*));
	while (++temp.x < general->mode)
	{
		general->map[temp.x] = (unsigned int*)malloc(general->mode * sizeof(unsigned int));
		temp.y = -1;
		while (++temp.y < general->mode)
		    general->map[temp.x][temp.y] = 0;
	}
	general->window = SDL_CreateWindow("MAP",
	        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
	        WIN_X, WIN_Y, SDL_WINDOW_SHOWN);
	general->renderer = SDL_CreateRenderer(general->window,
	        -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	general->x2 = 110;
	general->y2 = 110;
	general->drawing = 0;
	TTF_Init();
	general->font = TTF_OpenFont("font.ttf", 50);
	tex_join(general);
	general->done = SDL_FALSE;
}
