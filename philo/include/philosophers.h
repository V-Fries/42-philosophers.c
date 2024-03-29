/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 07:20:28 by vfries            #+#    #+#             */
/*   Updated: 2023/04/09 09:28:44 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>

typedef struct s_philosopher
{
	int				id;
	const int		*args;
	pthread_mutex_t	right_fork_mutex;
	pthread_mutex_t	*left_fork_mutex;
	struct timeval	start_time;
	struct timeval	time_to_die;
	pthread_mutex_t	time_to_die_mutex;
	bool			*philosopher_died;
	pthread_mutex_t	*philosopher_died_mutex;
	pthread_t		pthread;
	pthread_mutex_t	*execution_lock;
	int				nb_of_times_to_eat;
	pthread_mutex_t	nb_of_times_to_eat_mutex;
}	t_philosopher;

void			start_monitoring(t_philosopher *philosophers);
void			run_philosopher(t_philosopher *philosophers);
void			run_single_philosopher(t_philosopher *philosophers);

bool			no_philosophers_died(const t_philosopher *philosopher);
void			*philosopher_routine(void *philosopher_void);
int				print_state_change(const char *format,
					t_philosopher *philosopher);
int				philosopher_eats(t_philosopher *philosopher);
int				philosopher_sleeps(t_philosopher *philosopher);
void			sleep_till(const struct timeval goal,
					const t_philosopher *philosopher);

t_philosopher	*init_philosophers(const int *args, bool *philosopher_died,
					pthread_mutex_t	*philosopher_died_mutex);

void			destroy_philosophers(t_philosopher *philosophers, int size);
void			destroy_philosopher(t_philosopher *philosopher);

#endif //PHILOSOPHERS_H
