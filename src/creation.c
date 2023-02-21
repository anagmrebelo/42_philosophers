/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 23:37:00 by arebelo           #+#    #+#             */
/*   Updated: 2022/05/27 23:38:13 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

_Bool	thread_creation(t_params *param)
{
	time_t	i;

	if (!philo_creation(param) || !mutex_creation(param))
		return (0);
	i = 0;
	while (i < param->num_phil)
	{	
		param->philo[i].name = i + 1;
		if (pthread_create(&param->philo[i].th, NULL, &routine, param))
		{
			exit_clean(param);
			return (0);
		}
		i++;
	}
	return (1);
}

_Bool	mutex_creation(t_params *param)
{
	time_t	i;

	i = 0;
	param->mutex = malloc(sizeof(pthread_mutex_t) * param->num_phil);
	if (!param->mutex)
	{
		exit_clean(param);
		return (0);
	}
	while (i < param->num_phil)
	{
		pthread_mutex_init(&param->mutex[i], NULL);
		i++;
	}
	return (1);
}

_Bool	philo_creation(t_params *param)
{
	param->philo = malloc(sizeof(t_philo) * param->num_phil);
	if (!param->philo)
	{
		exit_clean(param);
		return (0);
	}
	fork_assignment(param);
	return (1);
}

void	fork_assignment(t_params *param)
{
	time_t	i;

	i = 0;
	while (i < param->num_phil)
	{
		param->philo[i].fork_right = i - 1;
		param->philo[i].fork_left = i;
		i++;
	}
	param->philo[0].fork_right = param->num_phil - 1;
}

_Bool	thread_detach(t_params *param)
{
	time_t	i;

	i = 0;
	while (i < param->num_phil)
	{
		if (pthread_detach(param->philo[i].th))
		{
			exit_clean(param);
			return (0);
		}
		i++;
	}
	return (1);
}
