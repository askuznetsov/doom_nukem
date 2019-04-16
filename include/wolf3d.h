/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:52:27 by tvoronyu          #+#    #+#             */
/*   Updated: 2019/01/24 20:46:38 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_WOLF3D_H
# define WOLF3D_WOLF3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <SDL.h>
# include <math.h>
# include <fcntl.h>
# include <SDL.h>
# include <SDL_image.h>
# include <SDL_mixer.h>
# include <SDL_ttf.h>
# include <time.h>
# include "../lib/libft/libft.h"
# include "../include/get_next_line.h"

# define WIDTH 1024
# define HEIGHT 768

typedef struct		s_raycast
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			plan_x;
	double			plan_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	double			dist_player;
	int				map_x;
	int				map_y;
	double			side;
	int				hit;
	int				step_x;
	int				step_y;
}					t_raycast;

typedef struct		s_draw
{
	double			weight;
	double			floor_wall_y;
	double			floor_wall_x;
	int				draw_start;
	int				draw_end;
	int				tex_x;
	int				tex_y;
	int				floor_tex_x;
	int				floor_tex_y;
	double			perp_wall_dist;
	double			wall_x;
	double			current_floor_x;
	double			current_floor_y;
	double			current_dist;
	int				line_height;
}					t_draw;

typedef	struct		s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Texture		*screen;
	SDL_Surface		*up;
	SDL_Surface		*up_1;
	SDL_Surface		*floor;
	SDL_Surface		*wall[7];
	Mix_Music		*mus[3];
	TTF_Font		*font_ttf;
	SDL_Surface		*font_surface;
	SDL_Rect		font_rect;
	SDL_Texture		*font_text;
	SDL_Event		event;
}					t_sdl;

typedef struct		s_wolf
{
	const Uint8		*keys;
	t_raycast		raycast;
	t_draw			draw;
	t_sdl			sdl;
	double			speed;
	Uint32			buf[HEIGHT][WIDTH];
	int				counter_str_on_map;
	int				loop;
	char			*name;
	char			**full_map;
	int				**array;
	int				width_arr;
	int				height_arr;
	int				pos_x;
	int				pos_y;
	int				count;
	int				code_error;
	int				x;
	int				y;
	int				d;
	int				pause;
	char			*test;
	int				tw;
	int				th;
	int				ww;
	int				wh;
	int				t1;
	int				t2;
	int				i;
	int				m;
	int				q;
	int				w;
	double			plan;
	double			dir;
	double			koef;
	int				count_array;
	int 			loop_shadow;
}					t_wolf;

int					main(int argc, char *argv[]);
void				ft_read(t_wolf *wolf);
void				ft_read_map_on_file(t_wolf *wolf);
int					ft_count_str_on_map(t_wolf *wolf);
void				ft_init_varible(t_wolf *wolf);
void				ft_init_all(t_wolf *wolf);
void				render_texture(t_wolf *wolf);
void				ft_draw_wall(t_wolf *wolf);
void				ft_draw_player(t_wolf *wolf);
void				ft_init_ttf(t_wolf *wolf);
void				ft_fps(t_wolf *wolf);
void				ft_error(int error, t_wolf *wolf);
int					ft_valid_error_arr_pos(t_wolf *wolf);
int					ft_valid(t_wolf *wolf);
void				ft_check_side_and_step_help(t_wolf *wolf);
void				ft_raycast(t_wolf *wolf);
void				ft_game(t_wolf *wolf);
void				ft_keys_2(t_wolf *wolf);
void				ft_keys_3(t_wolf *wolf);
void				ft_keys_4(t_wolf *wolf);
void				ft_keys_help(t_wolf *wolf);
void				keys(t_wolf *wolf);
void				ft_mouse_right(t_wolf *wolf);
void				ft_move_left(t_wolf *wolf);
void				ft_pause_2(t_wolf *wolf);
void				ft_keys_1(t_wolf *wolf);
void				ft_calc_wall(t_wolf *wolf);
void				ft_init_floor_ceil(t_wolf *wolf);
void				ft_floor_ceil_help(t_wolf *wolf, unsigned int *color);
void				render(t_wolf *wolf);
void				ft_init_raycast(t_wolf *wolf);
void				ft_check_side_and_step(t_wolf *wolf);
void				ft_check_wall(t_wolf *wolf);
void				ft_check_wall_dist(t_wolf *wolf);
void				ft_start_end(t_wolf *wolf);
int					ft_select_wall(t_wolf *wolf);
SDL_Surface			*load_image(char *path);
unsigned int		get_pixel_int(SDL_Surface *surface, int x, int y);
Mix_Music			*load_music(char *path);
void				ft_convert_char_to_int_map(t_wolf *wolf);
int					ft_check_rigth_and_left(t_wolf *wolf);
int					ft_check_ceil_and_floor(t_wolf *wolf);
int					ft_check_min_size_map(t_wolf *wolf);
int					ft_check_pos_player(t_wolf *wolf);
void				ft_free_mas(char **ret);
char				**ft_chrlen(char *str);
int					ft_count_chr(char **str);
int					ft_check_size_map(t_wolf *wolf);
void				ft_write_mas_int(int n, t_wolf *wolf, char **str);
int					ft_check_invalid_number(t_wolf *wolf);

#endif
