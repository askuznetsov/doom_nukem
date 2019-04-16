/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <okuznets@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:34:03 by okuznets          #+#    #+#             */
/*   Updated: 2019/04/16 21:12:43 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <header.h>

int		main(int argc, char **argv)
{
	t_general	general;

	if (argc == 4)
		ac_processing(&general, argv);
	else
	{
		ft_putstr("Usage: ./map [grid size] [-n || -e] [filename]\n");
		return (0);
	}
	general_setting(&general);
	if (SDL_Init(SDL_INIT_VIDEO) == 0)
	{
		init_sdl(&general);//to write init_sdl
	}
	return (0);
}
