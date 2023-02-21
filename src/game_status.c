/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:55:55 by arebelo           #+#    #+#             */
/*   Updated: 2022/05/30 16:56:05 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static _Bool	philo_dead_check(t_params *param)
{
	time_t	i;

	i = 0;
	while (i < param->num_phil)
	{
		if (get_time(param) - param->philo[i].time_last_eat > param->time_die)
		{
			status_died((t_params *)param, i);
			return (0);
		}
		i++;
	}
	return (1);
}

_Bool	game_on(t_params *param)
{
	time_t	i;

	if (!philo_dead_check(param))
		return (0);
	if (param->argc != 6)
		return (1);
	i = 0;
	while (i < param->num_phil)
	{
		if (param->philo[i].num_eat < param->num_eat)
		{
			return (1);
		}
		i++;
	}
	pthread_mutex_lock(&param->write_mutex);
	param->game_status = 1;
	return (0);
}
