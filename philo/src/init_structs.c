/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:12:41 by dasalaza          #+#    #+#             */
/*   Updated: 2025/03/21 21:12:39 by dasalaza         ###   ########.fr       */
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
		table->philosophers[i].meals_required = table->meals_required;
		table->philosophers[i].meals_eaten = 0;
		table->philosophers[i].time_of_death = -1;
		table->philosophers[i].left_fork = &(table->forks[i]);
		if (i == 0)
			table->philosophers[i].right_fork = &(table->forks[table->total_philos - 1]);
		else
			table->philosophers[i].right_fork = &(table->forks[i - 1]);
		pthread_mutex_init(&(table->philosophers[i].death_mutex), NULL);
		table->philosophers[i].table = table;
		i ++;
	}
	table->simulation_start_time = get_current_time_ms();
}

int	init_table(t_table *table, int ac, char **av)
{
	table->total_philos = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->meals_required = ft_atoi(av[5]);
	table->simulation_ended = 0;
	table->philosophers_fed = 0;
	table->forks = malloc(table->total_philos * sizeof(pthread_mutex_t));
	table->philosophers = malloc(table->total_philos * sizeof(t_philo));
	table->threads = malloc(table->total_philos * sizeof(pthread_t));
	if (!table->forks || !table->philosophers || !table->threads)
	{
		printf("Error: malloc in init_table\n");
		return (1);
	}
	return (0);
}
