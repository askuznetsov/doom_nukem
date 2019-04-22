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
    link = create_rect(xs, ys, x, y);//to write create_rect;
    SDL_RenderCopy(general.renderer, general.textur, NULL, link);
    free(link);
    SDL_FreeSurface(surface);
}

void    rework_drawing(t_general *general)
{
    SDL_SetRenderDrawColor(general->renderer, 0, 0, 0, 255);
    SDL_RenderClear(general->renderer);
    if (general->pos == 0 || general->pos == 5)
        put_text("Pick Texture", 165, *general, 1450);//to write put_text;
    else if (general->pos == 1)
        put_text("Pick two slots", 165, *general, 1450);
    else if (general->pos == 2 || general->pos == 6)
    {
        put_text("Set height", 165, *general, 1450);
        put_text(general->text, 685, &general, 1400);
    }
    else if (general->pos == 3)
        put_text("Pick wall", 165, *general, 1450);
    else if (general->pos == 4)
        put_text("EDIT: D, T, H", 165, *general, 1450);
    put_text("Save to file", 805, *general, 1450);
    set_rect_for_texture(general);//to write set_rect_for_texture;
    SDL_SetRenderDrawColor(general->renderer, 255, 255, 255, 0);
    draw_grid(*general);//to write draw_grid;
    draw_lines1(*general);//to write draw_lines1;
    draw_lines1_rect(*general);//to write draw_lines1_rect;
    SDL_RenderPresent(general->renderer);
}
void    matter(t_general *general)
{
    if (general->event.type == SDL_QUIT)
        general->done = SDL_TRUE;
    if (general->pos == 0)
        general_pos_0(general);//to write general_pos_0;
    else if (general->pos == 1)
        general_pos_1(general);//to write general_pos_1;
    else if ((general->pos == 2 || general->pos == 6) &&
    ft_strlen(general->text) <= 2)
        general_pos_2(general);//to write general_pos_2;
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