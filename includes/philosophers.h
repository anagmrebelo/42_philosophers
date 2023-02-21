/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:07:13 by arebelo           #+#    #+#             */
/*   Updated: 2022/05/29 18:42:22 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>

# define EAT	0
# define SLEEP 1
# define THINK 2
# define RIGHT 0
# define LEFT 1

typedef struct s_philo
{
	size_t			name;
	time_t			time_last_eat;
	time_t			num_eat;
	size_t			fork_right;
	size_t			fork_left;
	pthread_t		th;
}	t_philo;

typedef struct s_params
{
	time_t			init_time;
	time_t			counter;
	time_t			num_phil;
	time_t			time_die;
	time_t			time_eat;
	time_t			time_sleep;
	time_t			num_eat;
	int				argc;
	_Bool			game_status;
	t_philo			*philo;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	counter_mutex;
	pthread_mutex_t	write_mutex;
}	t_params;

// Utils
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(unsigned long count, size_t size);

//Init
_Bool	store_args(char **argv, t_params *param, int argc);
_Bool	init_time_mutex_thread(t_params *param);

//Creation
_Bool	thread_creation(t_params *param);
_Bool	mutex_creation(t_params *param);
_Bool	philo_creation(t_params *param);
void	fork_assignment(t_params *param);
_Bool	thread_detach(t_params *param);
void	*routine(void *param);

//Status
void	status_died(t_params *param, time_t i);
void	status_fork(t_params *param, time_t i);
void	status_eat(t_params *param, time_t i);
void	status_sleep(t_params *param, time_t i);
void	status_think(t_params *param, time_t i);
void	message_display(t_params *param, time_t i, char *str);
time_t	get_time(t_params *param);
_Bool	game_on(t_params *param);

//Exit
void	exit_clean(t_params *param);

#endif
