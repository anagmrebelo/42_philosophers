/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:07:34 by arebelo           #+#    #+#             */
/*   Updated: 2022/05/30 17:21:11 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	exit_clean(t_params *param)
{
	time_t	i;

	i = 0;
	if (param->philo)
		free(param->philo);
	if (param->mutex)
	{
		while (i < param->num_phil)
		{
			pthread_mutex_destroy(&param->mutex[i]);
			i++;
		}
		free(param->mutex);
	}
	pthread_mutex_destroy(&param->counter_mutex);
	pthread_mutex_destroy(&param->write_mutex);
	if (param)
		free(param);
}

static void	message_error(void)
{
	printf("The program takes the following arguments: ");
	printf("number_of_philosophers, time_to_die,");
	printf(" time_to_eat, time_to_sleep,");
	printf(" [number_of_times_each_philosopher_must_eat]\n");
}

int	main(int argc, char **argv)
{
	t_params		*param;

	param = ft_calloc(1, (sizeof(t_params)));
	if (!param)
		return (0);
	if (argc == 5 || argc == 6)
	{
		if (!store_args(argv, param, argc))
		{
			printf("Insert valid arguments\n");
			return (0);
		}
		if (!init_time_mutex_thread(param))
			return (0);
		thread_detach(param);
	}
	else
		message_error();
	exit_clean(param);
	return (0);
}
