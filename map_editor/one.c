/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <okuznets@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 18:00:08 by okuznets          #+#    #+#             */
/*   Updated: 2019/04/13 21:49:19 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	lines_inspect(t_general *general, int bars)
{
	t_solidus	side;
	char		*bar;
	char		**coords;

	while (bars --)
	{
		if (get_next_line(general->fd, &bar) <= 0)
			exit(0);
		coords = ft_strsplit(line, ' ');
		if (words_width(cords) != 6)
			exit(0);
		if ((side.texture_number = (abs(ft_atoi(coords[0])))) >= 16)
			exit(0);
		side.x1 = abs(ft_atoi(coords[1]));
		side.x2 = abs(ft_atoi(coords[3]));
		side.y1 = abs(ft_atoi(coords[2]));
		side.y2 = abs(ft_atoi(coords[4]));
		side.height = abs(ft_atoi(coords[5]));
		if (side.height > 300)
			exit(0);
		push_to_front(&general->lines, &side);
		words_loose(coords);
		free(bar);
	}
}

void	new(char *c, t_general *general)
{
	char *temp;

	if (!c)
		exit(0);
	system("tar -xzf ../package -C ../");
	temp = ft_strjoin("../maps/",c);
	general->fd = open(temp, O_RDWR | O_TRUNC | O_CREAT, 0666);
	free(temp);
	if (!general->fd)
		exit(0);
}

void	modify(char *c, t_general *general)
{
	char	**coords;
	char	*bar;

	coords = NULL;
	bar = NULL;
	system("tar -xzf ../package -C ../");
	if (!c)
		exit(0);
	if ((general->fd = open(c, O_RDONLY)) <= 0)
		exit(0);
	if (get_next_line(general->fd, &line) <= 0)
		exit(0);
	coords = ft_strsplit(bar, ' ');
	if (words_len(coords) != 2)
		exit(0);
	if ((ft_atoi(coords[1]) != general->mode))
		exit(0);
	if (ft_atoi(coords[0]) >= 1)
		general->z = 1;
	free(bar);
	lines_inspect(general, ft_atoi(coords[0]));
	words_loose(coords);
	close(general->fd);
	modify(c, general);
}

void	ac_processing(t_general general, char **argv)
{
	general->z = 0;
	if (ft_atoi(argv[1]) == 10 || ft_atoi(argv[1]) == 50)
		general->mode = ft_atoi(argv[1]);
	else
		exit(0);
	if (strcmp(argv[2], "-n") == 0)
		new(argv[3], general);
	else if (ft_strcmp(argv[2], "-e") == 0)
		modify(argv[3], general);
	else
		exit(0);
}
