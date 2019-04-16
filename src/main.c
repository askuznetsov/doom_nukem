/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 19:46:48 by tvoronyu          #+#    #+#             */
/*   Updated: 2019/01/24 21:01:14 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init_all(t_wolf *wolf)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		ft_error(3, wolf);
	if (!(wolf->sdl.win = SDL_CreateWindow("Wolf3D",
					SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED, WIDTH,
					HEIGHT, SDL_WINDOW_RESIZABLE
					| SDL_WINDOW_SHOWN)))
		ft_error(3, wolf);
	if (!(wolf->sdl.ren = SDL_CreateRenderer(wolf->sdl.win, -1,
					SDL_RENDERER_ACCELERATED
					| SDL_RENDERER_PRESENTVSYNC)))
		ft_error(3, wolf);
	if (!(wolf->sdl.screen = SDL_CreateTexture(wolf->sdl.ren,
					SDL_PIXELFORMAT_ARGB8888,
					SDL_TEXTUREACCESS_TARGET, WIDTH, HEIGHT)))
		ft_error(3, wolf);
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		ft_error(3, wolf);
	if (TTF_Init() < 0)
		ft_error(3, wolf);
	ft_init_varible(wolf);
}

int		ft_count_str_on_map(t_wolf *wolf)
{
	int		n;
	int		fd;
	char	*line;

	n = 0;
	fd = open(wolf->name, O_RDWR);
	if (fd > 2)
	{
		while (get_next_line(fd, &line))
		{
			if (line[0] != '\0')
			{
				n++;
			}
			free(line);
		}
		close(fd);
	}
	return (n);
}

void	ft_read_map_on_file(t_wolf *wolf)
{
	int		fd;
	char	*line;
	char	**str;

	line = NULL;
	str = NULL;
	fd = 0;
	if ((wolf->counter_str_on_map = ft_count_str_on_map(wolf)))
	{
		fd = open(wolf->name, O_RDWR);
		str = (char**)malloc(sizeof(char*) * wolf->counter_str_on_map + 1);
		str[wolf->counter_str_on_map] = NULL;
		wolf->counter_str_on_map = 0;
		while (get_next_line(fd, &line))
		{
		    if (line[0] != '\0')
		    {
                str[wolf->counter_str_on_map++] = ft_strjoin(line, "\n");
                wolf->count_array++;
            }
		    free(line);
		}
	}
	wolf->full_map = str;
	close(fd);
}

void	ft_read(t_wolf *wolf)
{
	int fd;
	
	fd = open(wolf->name, O_DIRECTORY);
	if (fd >= 0)
		ft_error(1, wolf);
	ft_read_map_on_file(wolf);
}

int		main(int argc, char *argv[])
{
	t_wolf *wolf;

	if (argc == 2)
	{
		wolf = (t_wolf*)malloc(sizeof(t_wolf));
		ft_bzero(wolf, sizeof(t_wolf));
		wolf->name = argv[1];
		ft_read(wolf);
		if (ft_valid(wolf))
			ft_error(2, wolf);
		ft_free_mas(wolf->full_map);
		ft_init_all(wolf);
		ft_game(wolf);
	}
	else
		ft_putendl("___Error___\nMany arguments or wrong map selection\n"
				"./wolf3d maps/...");
//	system("leaks wolf3d");
	return (0);
}
