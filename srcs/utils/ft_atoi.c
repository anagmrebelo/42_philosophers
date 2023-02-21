/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:51:38 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/22 00:06:44 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *str)
{
	unsigned int	nb;
	int				sign;

	nb = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (((nb * 10 + *str - '0') > INT_MAX) && sign == 1)
			return (-1);
		else if (((nb * 10 + *str - '0') > ((unsigned int)INT_MIN * -1))
			&& sign == -1)
			return (0);
		else
			nb = nb * 10 + *str++ - '0';
	}
	return (nb * sign);
}
