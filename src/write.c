/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 23:17:12 by arebelo           #+#    #+#             */
/*   Updated: 2022/05/30 16:03:21 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	message_display(t_params *param, time_t i, char *str)
{
	time_t	time;

	pthread_mutex_lock(&param->write_mutex);
	time = get_time(param);
	printf("%ld %zu %s\n", time, param->philo[i].name, str);
	pthread_mutex_unlock(&param->write_mutex);
}
