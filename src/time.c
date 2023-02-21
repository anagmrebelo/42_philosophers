/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:03:56 by arebelo           #+#    #+#             */
/*   Updated: 2022/05/30 15:20:24 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

time_t	get_time(t_params *param)
{
	struct timeval	time;

	while (gettimeofday(&time, NULL))
	{
	}
	return ((time.tv_sec * 1000 + time.tv_usec / 1000) - param->init_time);
}
