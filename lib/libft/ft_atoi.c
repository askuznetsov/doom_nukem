/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:55:59 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/04/05 09:22:50 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	size_t				i;
	int					minus;
	unsigned long int	number;

	number = 0;
	minus = 1;
	ft_space(str, &i);
	if (str[i] == '-')
		minus = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		if ((number > 922337203685477580 || (number == 922337203685477580
						&& (str[i] - '0') > 7)) && minus == 1)
			return (-1);
		else if ((number > 922337203685477580 || (number == 922337203685477580
						&& (str[i] - '0') > 8)) && minus == -1)
			return (0);
		number *= 10;
		number += (str[i++] - 48);
	}
	if (minus < 0)
		return (-number);
	return (number);
}
