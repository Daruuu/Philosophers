/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:59:50 by dasalaza          #+#    #+#             */
/*   Updated: 2025/03/21 18:09:24 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
// Created by daruuu on 3/18/25.

/**
 * args:
 * number_of_philosophers
 * time_to_die
 * time_to_eat
 * time_to_sleep
 * [number_of_times_each_philosopher_must_eat]
 */
void	print_if_no_args(void)
{
	printf("invalid number of arguments :(\n");
	printf("Need 4-5 args\n1: number of philosophers \n");
	printf("2: time to die\n3. time to eat\n4. time to sleep\n");
	printf("5: [optional] number of times each philosopher must eat\n");
}

int	main(int ac, char **av)
{
	t_table		table;

	if (ac < 5 || ac > 6)
	{
		print_if_no_args();
		return (1);
	}
	if (check_valid_args(ac, av) == 1)
		printf("Error: invalid input(solo integers :(\n");
	if (init_table(&table, ac, av) != 0)
	{
		free_table(&table);
		return (1);
	}
	if (table.total_philos == 0)
		return (0);
	monitoring(&table);
	if (join_threads(&table) != 0)
	{
		free_table(&table);
		return (1);
	}
	destroy_mutex(&table);
	free_table(&table);
	return (0);
}
