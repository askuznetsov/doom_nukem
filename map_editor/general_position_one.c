//
// Created by Oleksandr KUZNETSOV on 2019-04-23.
//

#include "header.h"

void			general_pos_0(t_general *general)
{
    pos_0_pick_tex(general);//to write
}

void			general_pos_1(t_general *general)
{
    pos_1_set_dot(general);//to write
}

void			general_pos_2(t_general *general)
{
    if (general->event.type == SDL_TEXTINPUT)
        ft_strcat(general->text, general->event.text.text);
}

void			general_pos_3(t_general *general)
{
    general_pos_3_edit(general);//to write
}
