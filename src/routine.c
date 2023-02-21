/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 23:21:20 by arebelo           #+#    #+#             */
/*   Updated: 2022/05/30 16:46:45 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*routine(void *param)
{
	time_t	i;

	pthread_mutex_lock(&((t_params *)param)->counter_mutex);
	i = ((t_params *)param)->counter;
	((t_params *)param)->counter += 1;
	pthread_mutex_unlock(&((t_params *)param)->counter_mutex);
	if (i % 2 != 0)
		usleep(10000);
	while (1)
	{
		status_fork((t_params *)param, i);
		status_eat((t_params *)param, i);
		status_sleep((t_params *)param, i);
		status_think((t_params *)param, i);
	}
	return (NULL);
}
