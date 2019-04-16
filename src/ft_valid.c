/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 19:22:25 by tvoronyu          #+#    #+#             */
/*   Updated: 2019/01/24 21:02:10 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_error(int error, t_wolf *wolf)
{
	if (error == 1)
		ft_putendl("Error !");
	else
		ft_putendl("Error map !");
	wolf = NULL;
	exit(0);
}

int		ft_valid_error_arr_pos(t_wolf *wolf)
{
	int n;

	if ((wolf->width_arr = ft_atoi(wolf->full_map[0])) > 0
			&& (wolf->height_arr = ft_atoi(wolf->full_map[1])) > 0
			&& (wolf->raycast.pos_x = ft_atoi(wolf->full_map[2])) > 0
			&& (wolf->raycast.pos_y = ft_atoi(wolf->full_map[3])) > 0)
	{
		wolf->pos_x = ft_atoi(wolf->full_map[2]);
		wolf->pos_y = ft_atoi(wolf->full_map[3]);
		n = ft_check_size_map(wolf);
		if (n == 0 || wolf->width_arr > n
				|| wolf->height_arr != wolf->counter_str_on_map - 4
				|| wolf->width_arr < 3 || wolf->raycast.pos_x > n
				|| wolf->raycast.pos_y > wolf->count_array - 5
				|| ft_check_min_size_map(wolf) || ft_check_pos_player(wolf)
				|| wolf->array[wolf->pos_y - 1][wolf->pos_x - 1] != 0)
			return (1);
		wolf->raycast.pos_x -= 0.5;
		wolf->raycast.pos_y -= 0.5;
		return (0);
	}
	else
		return (1);
}

int		ft_check_invalid_number(t_wolf *wolf)
{
	int n;
	int m;

	m = -1;
	while (++m < wolf->height_arr)
	{
		n = -1;
		while (++n < wolf->width_arr)
		{
			if (wolf->array[m][n] > 9 || wolf->array[m][n] < 0)
				return (1);
		}
	}
	return (0);
}

int		ft_valid(t_wolf *wolf)
{
	if (wolf->counter_str_on_map >= 7)
	{
		if (ft_valid_error_arr_pos(wolf))
			return (1);
		if (ft_check_invalid_number(wolf))
			return (1);
	}
	else
		ft_error(4, wolf);
	return (0);
}
