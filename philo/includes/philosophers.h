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
	int					id;
	int					total_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					meals_required;
	int					meals_eaten;
	int					time_of_death;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		death_mutex;
	struct s_table		*table;
}		t_philo;

typedef struct s_table
{
	int				total_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_required;
	int				simulation_ended;
	int				philosophers_fed;
	int				simulation_start_time;
	pthread_mutex_t	*forks;
	struct s_philo	*philosophers;
	pthread_t		*threads;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	simulation_end_mutex;
	pthread_mutex_t	philosophers_fed_mutex;
}		t_table;

//	init_structs.c
void	init_philos(t_table *table);
int		init_table(t_table *table, int ac, char **av);

//	check_arguments.c
int		check_valid_args(int ac, char **av);
int		ft_atoi(const char *str);

//	get_time.c
int		get_current_time_ms(void);

#endif
