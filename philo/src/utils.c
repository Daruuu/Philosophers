/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:54:02 by dasalaza          #+#    #+#             */
/*   Updated: 2025/04/08 19:54:05 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	join_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->total_philos)
	{
		if (pthread_join(table->threads[i], NULL) != 0)
			return (1);
		i ++;
	}
	return (0);
}

void	destroy_mutex(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->total_philos)
	{
		pthread_mutex_destroy(&(table->forks[i]));
		pthread_mutex_destroy(&(table->philosophers[i].death_mutex));
		i ++;
	}
	pthread_mutex_destroy(&(table->philos_full_mutex));
	pthread_mutex_destroy(&(table->print_mutex));
	pthread_mutex_destroy(&(table->end_mutex));
}

void	free_table(t_table *table)
{
	if (table->forks)
		free(table->forks);
	if (table->philosophers)
		free(table->philosophers);
	if (table->threads)
		free(table->threads);
}
