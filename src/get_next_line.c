/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 13:10:43 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/05/22 15:38:50 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_end(char **buf, int fd, int ret, char **line)
{
	if (ret == BUFF_SIZE)
		return (1);
	else
	{
		*line = ft_strdup(buf[fd]);
		ft_strdel(&buf[fd]);
	}
	return (1);
}

int		ft_write_line(char **buf, char **line, int fd, int ret)
{
	char	*tmp;
	int		len;
	int		result;

	len = 0;
	while (buf[fd][len] != '\n' && buf[fd][len] != '\0')
		len++;
	if (buf[fd][len] == '\n')
	{
		*line = ft_strsub(buf[fd], 0, len);
		tmp = ft_strdup(buf[fd] + len + 1);
		free(buf[fd]);
		buf[fd] = tmp;
		if (buf[fd][0] == '\0')
			ft_strdel(&buf[fd]);
	}
	else if (buf[fd][len] == '\0')
	{
		result = ft_end(buf, fd, ret, line);
		return (result);
	}
	return (1);
}

char	*ft_read_line(char **buf, int fd, int *ret)
{
	char buf_size[BUFF_SIZE + 1];
	char *tmp;

	while ((*ret = read(fd, buf_size, BUFF_SIZE)) > 0)
	{
		buf_size[*ret] = '\0';
		if (buf[fd] == NULL)
			buf[fd] = ft_strnew(1);
		tmp = ft_strjoin(buf[fd], buf_size);
		free(buf[fd]);
		buf[fd] = tmp;
		if (ft_strchr(buf_size, '\n'))
			break ;
	}
	return (buf[fd]);
}

int		get_next_line(int fd, char **line)
{
	static char *buf[4864];
	int			ret;
	int			result;
	char		error[1];

	if (fd < 0 || !(line) || BUFF_SIZE < 0 || read(fd, error, 0) == -1
			|| fd > 4864)
		return (-1);
	buf[fd] = ft_read_line(buf, fd, &ret);
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (buf[fd] == NULL || buf[fd][0] == '\0'))
		return (0);
	result = 0;
	while (1)
	{
		result = ft_write_line(buf, line, fd, ret);
		if (result == 1)
			break ;
	}
	return (1);
}
