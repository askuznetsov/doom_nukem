/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <okuznets@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:18:03 by okuznets          #+#    #+#             */
/*   Updated: 2019/04/13 18:44:40 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HEADER_H
# define HEADER_H

#include "../lib/SDL/SDL2.framework/Headers/SDL.h"
#include "../lib/SDL/SDL2_image.framework/Headers/SDL_image.h"
#include "../lib/SDL/SDL2_ttf.framework/Headers/SDL_ttf.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../lib/libft/libft.h"
#include "../include/get_next_line.h"

# define WIN_X 1900
# define WIN_Y 1000
# define BAR_X 1400
# define BAR_Y 100
# define BAR_W 400
# define BAR_H 800
# define MAP_REC_X 100
# define MAP_REC_Y 100
# define MAP_REC_W 1300
# define MAP_REC_H 900

typedef struct		s_tools
{
	int		x;
	int		y;
}					t_tools;

typedef struct		s_rect
{
	int		x;
	int		y;
	int		w;
	int		h;
}					t_rect;

typedef struct		s_solidus
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	unsigned int	texture_number;
	int				height;
	struct s_line	*next;
}					t_solidus;

typedef struct		s_general
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture[16];
	SDL_Texture		*textur;
	SDL_Rect		texture_rect[18];
	TTF_Font		*font;
	SDL_Bool		done;
	SDL_Event		event;
	int             drawing;
	int				pos;
	int				current_texture;
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				fd;
	int				mode;
	int				xmode;
	int				ymode;
	unsigned int	**map;
	char			text[9];
	t_line			*lines;
	t_line			*to_edit;
}					t_general;

#endif
