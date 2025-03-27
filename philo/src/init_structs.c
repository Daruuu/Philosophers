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

void	init_philosophers(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->total_philos)
	{
		table->philosophers[i].id = i;
		table->philosophers[i].total_philos = table->total_philos;
		table->philosophers[i].time_to_die = table->time_to_die;
		table->philosophers[i].
		table->philosophers[i].
		table->philosophers[i].
		table->philosophers[i].
		table->philosophers[i].
	}

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

int	fill_args_into_simulation(int ac, char **av, t_table *table)
{
	table->total_philos = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->meals_required = ft_atoi(av[5]);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned int	i;
	long			result;
	int				sign;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i ++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = (result * 10) + (str[i] - '0');
		else
			return (-1);
		if (result > INT_MAX)
			return (-1);
		i ++;
	}
	return (sign * (int) result);
}

int	check_valid_args(int ac, char **av)
{
	int	i;
	int	tmp;

	i = 1;
	while (i < ac)
	{
		tmp = (int) ft_atoi(av[i]);
		if (tmp != -1)
			i ++;
		else
		{
			printf("Error: invalid input\n");
			return (1);
		}
	}
	return (0);
}
