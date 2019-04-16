/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:44:06 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/03/24 12:13:16 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb2;
	char			s;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	nb2 = n;
	if (nb2 >= 10)
	{
		ft_putnbr_fd((nb2 / 10), fd);
		ft_putnbr_fd((nb2 % 10), fd);
	}
	else
	{
		s = n + '0';
		write(fd, &s, 1);
	}
}
