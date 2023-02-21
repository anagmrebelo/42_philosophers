/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:51:21 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/22 00:06:35 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	status_died(t_params *param, time_t i)
{	
	message_display(param, i, "died");
	pthread_mutex_lock(&param->write_mutex);
	param->game_status = 1;
}

void	status_fork(t_params *param, time_t i)
{
	pthread_mutex_lock(&param->mutex[param->philo[i].fork_left]);
	message_display(param, i, "has taken a fork");
	pthread_mutex_lock(&param->mutex[param->philo[i].fork_right]);
	message_display(param, i, "has taken a fork");
}

void	status_eat(t_params *param, time_t i)
{
	time_t	time;

	time = get_time(param);
	message_display(param, i, "is eating");
	param->philo[i].time_last_eat = time;
	param->philo[i].num_eat++;
	while (get_time(param) < time + param->time_eat)
	{	
		usleep(200);
	}
	pthread_mutex_unlock(&param->mutex[param->philo[i].fork_left]);
	pthread_mutex_unlock(&param->mutex[param->philo[i].fork_right]);
}

void	status_sleep(t_params *param, time_t i)
{
	time_t	time;

	time = get_time(param);
	message_display(param, i, "is sleeping");
	while (get_time(param) < time + param->time_sleep)
	{	
		usleep(200);
	}
}

void	status_think(t_params *param, time_t i)
{
	message_display(param, i, "is thinking");
}
