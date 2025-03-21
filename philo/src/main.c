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
 * Tu(s) programa(s) debe(n) aceptar los siguientes argumentos:
 * number_of_philosophers
 * time_to_die
 * time_to_eat
 * time_to_sleep
 * [number_of_times_each_philosopher_must_eat]
 */

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		printf("invalid number of arguments :(\n");
		printf("Need 4-5 args\n1: number of philosophers\n");
		printf("2: time to die\n3. time to eat\n4. time to sleep\n");
		printf("[optional] number of times each plhilopspher must eat\n");
		return (1);
	}
	if (check_valid_args(ac, av) == 1)
		printf("Error: invalid input(solo integers :(\n");
	else
	{
		printf("valid input\n");
	}
	return (0);
}
