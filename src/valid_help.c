/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 20:04:33 by tvoronyu          #+#    #+#             */
/*   Updated: 2019/01/24 20:08:21 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_convert_char_to_int_map(t_wolf *wolf)
{
	int n;

	n = 0;
	wolf->array = (int**)malloc(sizeof(int*) * wolf->height_arr);
	while (n < wolf->height_arr)
	{
		ft_write_mas_int(n, wolf, ft_chrlen(wolf->full_map[n + 4]));
		n++;
	}
}

int		ft_check_rigth_and_left(t_wolf *wolf)
{
	int n;

	n = 0;
	while (n < wolf->height_arr)
	{
		if (wolf->array[n][0] < 1 || wolf->array[n][0] > 9
				|| wolf->array[n][wolf->width_arr - 1] < 1
				|| wolf->array[n][wolf->width_arr - 1] > 9)
			return (1);
		n++;
	}
	return (0);
}

int		ft_check_ceil_and_floor(t_wolf *wolf)
{
	int n;

	n = 0;
	while (n < wolf->width_arr)
	{
		if (wolf->array[0][n] < 1 || wolf->array[0][n] > 9
				|| wolf->array[wolf->height_arr - 1][n] < 1
				|| wolf->array[wolf->height_arr - 1][n] > 9)
			return (1);
		n++;
	}
	return (ft_check_rigth_and_left(wolf));
}

int		ft_check_min_size_map(t_wolf *wolf)
{
	ft_convert_char_to_int_map(wolf);
	return (ft_check_ceil_and_floor(wolf));
}

int		ft_check_pos_player(t_wolf *wolf)
{
	int n;
	int m;

	n = 0;
	while (n < wolf->height_arr)
	{
		m = 0;
		while (m < wolf->width_arr)
		{
			if (wolf->array[n][m] == 0)
				return (0);
			m++;
		}
		n++;
	}
	return (1);
}
