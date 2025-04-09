/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:12:41 by dasalaza          #+#    #+#             */
/*   Updated: 2025/04/09 12:32:32 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	init_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->total_philos)
	{
		table->philosophers[i].id = i + 1;
		table->philosophers[i].total_philos = table->total_philos;
		table->philosophers[i].time_to_die = table->time_to_die;
		table->philosophers[i].time_to_eat = table->time_to_eat;
		table->philosophers[i].time_to_sleep = table->time_to_sleep;
		table->philosophers[i].meals_count = table->meals_count;
		table->philosophers[i].meals_consumed = 0;
		table->philosophers[i].time_of_death = NO_MEALS_REQUIRED;
		table->philosophers[i].fork_left = &(table->forks[i]);
		if (i == 0)
			table->philosophers[i].fork_right = \
				&(table->forks[table->total_philos - 1]);
		else
			table->philosophers[i].fork_right = &(table->forks[i - 1]);
		pthread_mutex_init(&(table->philosophers[i].death_mutex), NULL);
		table->philosophers[i].table = table;
		i ++;
	}
	table->start_time_simulation = get_current_time_ms();
}

void	init_mutex(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->total_philos)
	{
		pthread_mutex_init(&(table->forks[i]), NULL);
		i ++;
	}
	pthread_mutex_init(&(table->print_mutex), NULL);
	pthread_mutex_init(&(table->philos_full_mutex), NULL);
	pthread_mutex_init(&(table->end_mutex), NULL);
}

/**
 * @param table iterate throught table->total_philos
 * and use pthread_create para iterar por N (total_philos) and create
 * @return  true or false
 */
int	init_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->total_philos)
	{
		if (pthread_create(&(table->threads[i]), NULL, &routine_philo,
				&(table->philosophers[i])) != 0)
			return (1);
		i ++;
	}
	return (0);
}

static int	alloc_memory_forks_philos_threads(t_table *table)
{
	table->forks = malloc(table->total_philos * sizeof(pthread_mutex_t));
	table->philosophers = malloc(table->total_philos * sizeof(t_philo));
	table->threads = malloc(table->total_philos * sizeof(pthread_t));
	if (!table->forks || !table->philosophers || !table->threads)
		return (1);
	return (0);
}

/**
 * @brief Init the simulation table with philosophers, forks, and threads.
 *
 * @param table Pointer to the table structure to init.
 * @param ac Argument count from the command line.
 * @param av Argument vector from the command line.
 *
 * @return int Returns 0 on success,
 * or 1 if an error occurs during memory allocation or thread creation.
 */
int	init_table(t_table *table, int ac, char **av)
{
	table->total_philos = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	table->meals_count = NO_MEALS_REQUIRED;
	if (ac == 6)
		table->meals_count = ft_atoi(av[5]);
	table->end_simulation = 0;
	table->philos_fed_full = 0;
	if (alloc_memory_forks_philos_threads(table) != 0)
		return (1);
	init_mutex(table);
	init_philos(table);
	if (init_threads(table) != 0)
	{
		printf("Error: init threads in init_data\n");
		return (1);
	}
	return (0);
}
