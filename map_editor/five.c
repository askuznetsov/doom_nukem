//
// Created by User on 21.04.2019.
//

#include "header.h"

SDL_Rect    *create_rect(int x, int y, int w, int  h)
{
    SDL_Rect    *new;

    new = (SDL_Rect*)(malloc(sizeof(SDL_Rect)));
    new->x = x;
    new->y = y;
    new->w = w;
    new->h = h;
    return (new);
}