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

# define ONE_PHILO_STR "has taken left fork"
# define LEFT_FORK_STR "has taken left fork"
# define RIGHT_FORK_STR "has taken right fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DEAD_PH 1
# define FULL_PH 2
# define FULL_PHILOS "Philos are Full\n"
# define NO_MEALS_REQUIRED -1


typedef struct s_philo
{
	int					id;
	int					total_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					meals_count;
	int					meals_consumed;
	int					time_of_death;
	pthread_mutex_t		*fork_right;
	pthread_mutex_t		*fork_left;
	pthread_mutex_t		death_mutex;
	struct s_table		*table;
}		t_philo;

typedef struct s_table
{
	int				total_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_count;
	int				end_simulation;
	int				philos_fed_full;
	int				start_time_simulation;
	pthread_mutex_t	*forks;
	struct s_philo	*philosophers;
	pthread_t		*threads;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	end_mutex;
	pthread_mutex_t	philos_full_mutex;
}		t_table;

//	init_structs.c
void	init_philos(t_table *table);
int		init_table(t_table *table, int ac, char **av);

//	check_arguments.c
int		check_valid_args(int ac, char **av);
int		ft_atoi(const char *str);

//	get_time.c
int		get_current_time_ms(void);

//	print.c
void	print_states_philos(t_philo *philo, char *str_state);
void	print_end_simulation(t_table *table, int end, int i);
int		ft_usleep(int milliseconds);
int		count_fully_fed_philos(t_table *table);

//	routine_philos.c
void	*routine_philo(void * table_philo);
void	monitoring(t_table *table);

//	utils.c

int		join_threads(t_table *table);
void	destroy_mutex(t_table *table);
void	free_table(t_table *table);

#endif
