//
// Created by User on 21.04.2019.
//

#include "header.h"

SDL_Rect    *make_rectangle(int x, int y, int w, int  h)
{
    SDL_Rect    *new;

    new = (SDL_Rect*)(malloc(sizeof(SDL_Rect)));
    new->x = x;
    new->y = y;
    new->w = w;
    new->h = h;
    return (new);
}

void        rectangle_for_texture(t_general *general)
{
    int i;
    int x;
    int y;

    i = 0;
    x = 1375;
    y = 250;
    while (i < 16)
    {
        if (i == 4 || i == 8 || i == 12)
        {
            y += 100;
            x = 1375;
        }
        general->texture_rect[i].x = x;
        general->texture_rect[i].y = y;
        general->texture_rect[i].w = 75;
        general->texture_rect[i].h = 75;
        if (i < 16)
            SDL_RenderCopy(general->renderer, general->texture[i], NULL, &general->texture_rect[i]);
        x += 100;
        i++;
    }
}

void        mesh(t_general general)
{
    int y;
    int x;

    y = 100;
    x = 100;
    while (x < 1300)
    {
        y = 100;
        while (y < 900)
        {
            SDL_RenderDrawLine(general.renderer, x, y, x + general.xmode, y);
            SDL_RenderDrawLine(general.renderer, x, y, x, y + general.ymode);
            y += general.ymode;
        }
        x += general.xmode;
    }
}

void			dash_draw(t_general general)
{
    t_solidus	*bar;
    int		x;
    int		y;
    float	t;

    bar = general.lines;
    while (bar)
    {
        t = 0;
        while (t < 1)
        {
            x = bar->x1 * (1. - t) + bar->x2 * t;
            y = bar->y1 * (1. - t) + bar->y2 * t;
            pointexture(x, y, &global, bar);
            t += .01;
        }
        bar = bar->next;
    }
}

