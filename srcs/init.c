/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 00:07:50 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/22 00:06:35 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

_Bool	check_errors(t_params *param, int argc)
{
	if (!param->num_phil || param->num_phil < 0
		|| !param->time_die || param->time_die < 0
		|| !param->time_eat || param->time_eat < 0
		|| !param->time_sleep || param->time_sleep < 0)
	{
		exit_clean(param);
		return (0);
	}
	if (argc == 6)
	{
		if (!param->num_eat || param->num_eat < 0)
		{
			exit_clean(param);
			return (0);
		}
	}
	return (1);
}

_Bool	store_args(char **argv, t_params *param, int argc)
{
	param->argc = argc;
	param->num_phil = ft_atoi((const char *)argv[1]);
	param->time_die = ft_atoi((const char *)argv[2]);
	param->time_eat = ft_atoi((const char *)argv[3]);
	param->time_sleep = ft_atoi((const char *)argv[4]);
	if (argc == 6)
		param->num_eat = ft_atoi((const char *)argv[5]);
	else
		param->num_eat = -1;
	if (!check_errors(param, argc))
		return (0);
	return (1);
}

_Bool	init_time_mutex_thread(t_params *param)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
	{
		exit_clean(param);
		return (0);
	}
	param->init_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	pthread_mutex_init(&param->counter_mutex, NULL);
	pthread_mutex_init(&param->write_mutex, NULL);
	if (!thread_creation(param))
	{
		exit_clean(param);
		return (0);
	}
	while (game_on(param))
	{
	}
	return (1);
}
