//
// Created by Oleksandr KUZNETSOV on 2019-04-22.
//

#include "header.h"

void			pointexture(int x, int y, t_general *general, t_solidus *cur)
{
    SDL_Rect	*link;
    t_tools		xy;

    xy.x = 100;
    while (xy.x < 1300)
    {
        xy.y = 100;
        while (xy.y < 900)
        {
            if (x > xy.x && y > xy.y
                && x < xy.x + general->xmode && y < xy.y + general->ymode)
            {
                link = make_rectangle(xy.x, xy.y, general->xmode, general->ymode);
                SDL_RenderCopy(general->renderer,
                               general->texture[cur->texture_number], NULL, link);
                general->map[(xy.x - 100) / general->xmode][(xy.y - 100) /
                                                          general->ymode] = ((((unsigned int)(cur->texture_number + 1))
                        << 16) |
                                                                            (unsigned int)(cur->height));
                free(link);
            }
            xy.y += general->ymode;
        }
        xy.x += general->xmode;
    }
}

void			dash_draw_rectangle(t_general general)
{
    SDL_Rect *link;

    link = make_rectangle(100, 100, 1200, 800);
    SDL_RenderDrawRect(general.renderer, link);
    free(link);
    link = make_rectangle(1375, 125, 375, 100);
    SDL_RenderDrawRect(general.renderer, link);
    free(link);
    link = make_rectangle(1375, 775, 375, 100);
    SDL_RenderDrawRect(general.renderer, link);
    free(link);
    link = make_rectangle(1375, 650, 375, 100);
    SDL_RenderDrawRect(general.renderer, link);
    free(link);
    link = make_rectangle(1350, 100, 425, 800);
    SDL_RenderDrawRect(general.renderer, link);
    free(link);
}

