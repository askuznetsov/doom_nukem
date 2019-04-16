/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_help_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 20:08:35 by tvoronyu          #+#    #+#             */
/*   Updated: 2019/01/24 20:12:05 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_free_mas(char **ret)
{
	int i;

	i = 0;
	while (ret[i])
		free(ret[i++]);
	free(ret);
}

char	**ft_chrlen(char *str)
{
	char **split;
	char **s2;

	split = NULL;
	s2 = NULL;
	split = ft_strsplit(str, '\n');
	if (split != NULL)
	{
		s2 = ft_strsplit(split[0], ' ');
		ft_free_mas(split);
		return (s2);
	}
	return (NULL);
}

int		ft_count_chr(char **str)
{
	int n;

	n = 0;
	while (str[n])
		n++;
	ft_free_mas(str);
	return (n);
}

int		ft_check_size_map(t_wolf *wolf)
{
	int n;

	n = 4;
	while (wolf->full_map[n + 1] != NULL)
	{
		if (ft_count_chr(ft_chrlen(wolf->full_map[n]))
				!= ft_count_chr(ft_chrlen(wolf->full_map[n + 1])))
			return (0);
		n++;
	}
	return (ft_count_chr(ft_chrlen(wolf->full_map[n])));
}

void	ft_write_mas_int(int n, t_wolf *wolf, char **str)
{
	int m;

	m = 0;
	wolf->array[n] = (int*)malloc(sizeof(int) * wolf->width_arr);
	while (m < wolf->width_arr)
	{
		wolf->array[n][m] = ft_atoi(str[m]);
		m++;
	}
	ft_free_mas(str);
}
