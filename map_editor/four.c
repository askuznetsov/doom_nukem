//
// Created by User on 20.04.2019.
//

#include "header.h"

void    set_txt(char *c, int ys, t_general general, int xs)
{
    int         x;
    int         y;
    SDL_Color   color;
    SDL_Surface *surface;
    SDL_Rect    *link;

    x = 30;
    y = 30;
    color.r = 255;
    color.g = 255;
    color.b = 255;
    surface = TTF_RenderText_Solid(general.font, c, color);
    general.textur = SDL_CreateTextureFromSurface(general.renderer, surface);
    SDL_QueryTexture(general.textur, NULL, NULL, &x, &y);
    link = make_rectangle(xs, ys, x, y);
    SDL_RenderCopy(general.renderer, general.textur, NULL, link);
    free(link);
    SDL_FreeSurface(surface);
}

void    rework_drawing(t_general *general)
{
    SDL_SetRenderDrawColor(general->renderer, 0, 0, 0, 255);
    SDL_RenderClear(general->renderer);
    if (general->pos == 0 || general->pos == 5)
        set_txt("Pick Texture", 165, *general, 1450);
    else if (general->pos == 1)
        set_txt("Pick two slots", 165, *general, 1450);
    else if (general->pos == 2 || general->pos == 6)
    {
        set_txt("Set height", 165, *general, 1450);
        set_txt(general->text, 685, &general, 1400);
    }
    else if (general->pos == 3)
        set_txt("Pick wall", 165, *general, 1450);
    else if (general->pos == 4)
        set_txt("EDIT: D, T, H", 165, *general, 1450);
    set_txt("Save to file", 805, *general, 1450);
    rectangle_for_texture(general);
    SDL_SetRenderDrawColor(general->renderer, 255, 255, 255, 0);
    mesh(*general);
    dash_draw(*general);
    dash_draw_rectangle(*general);
    SDL_RenderPresent(general->renderer);
}
void    matter(t_general *general)
{
    if (general->event.type == SDL_QUIT)
        general->done = SDL_TRUE;
    if (general->pos == 0)
        general_pos_0(general);
    else if (general->pos == 1)
        general_pos_1(general);
    else if ((general->pos == 2 || general->pos == 6) &&
    ft_strlen(general->text) <= 2)
        general_pos_2(general);
    if (general->pos == 2 || general->pos == 6)
        general_pos_26(general);//to write general_pos_26;
    if (general->pos == 3)
        general_pos_3(general);
    if (general->pos == 4)
    {
        chech_for_d_t_h(general);//to write chech_for_d_t_h;
        rework_drawing(general);
    }
    if (general->pos == 5)
        general_pos_5(general);
    rework_drawing(general);
}

void    loop(t_general general)
{
    while (!global.done)
    {
        while (SDL_PollEvent(&general.event))
            matter(&general);
    }
}