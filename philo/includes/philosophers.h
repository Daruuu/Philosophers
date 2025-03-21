/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:24:33 by dasalaza          #+#    #+#             */
/*   Updated: 2025/03/21 19:38:28 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				eat_time;
	int				think_time;
	int				sleep_time;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*death_mutex;
}		t_philo;

typedef struct table
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philo_must_sleep;

}		t_table;

int	check_valid_args(int ac, char **av);
int	ft_atoi(const char *str);

#endif
