/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 07:20:33 by vfries            #+#    #+#             */
/*   Updated: 2023/03/16 07:20:34 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TIME_H
# define PHILO_TIME_H

# include <sys/time.h>

# include "philosophers.h"

# define NB_OF_USECONDS_IN_A_SECOND 1000000
# define NB_OF_USECONDS_IN_A_MILLISECOND 1000

struct timeval	get_current_time(void);
long long		get_timestamp(const t_philosopher *philosopher,
					const struct timeval current_time);
void			timeval_add_ms(struct timeval *tv, const int n);
int				timeval_compare(const struct timeval t1,
					const struct timeval t2);

#endif //PHILO_TIME_H
