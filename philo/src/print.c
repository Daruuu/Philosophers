/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:02:04 by dasalaza          #+#    #+#             */
/*   Updated: 2025/04/08 18:18:50 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	print_states_philos(t_philo *philo, char *str_state)
{
	int		end_flag;
	char	*color;

	pthread_mutex_lock(&(philo->table->end_mutex));
	end_flag = philo->table->end_simulation;
	pthread_mutex_unlock(&(philo->table->end_mutex));
	if (end_flag == 0)
	{
		if (ft_strcmp(str_state, LEFT_FORK_STR) == 0 \
			|| ft_strcmp(str_state, RIGHT_FORK_STR) == 0)
			color = YELLOW;
		else if (ft_strcmp(str_state, EATING) == 0)
			color = GREEN;
		else if (ft_strcmp(str_state, SLEEPING) == 0)
			color = BLUE;
		else if (ft_strcmp(str_state, THINKING) == 0)
			color = CYAN;
		else
			color = DEFA;
		pthread_mutex_lock(&(philo->table->print_mutex));
		printf("%s%i %i %s\033[0m\n", color,
			get_current_time_ms() - philo->table->start_time_simulation,
			philo->id, str_state);
		pthread_mutex_unlock(&(philo->table->print_mutex));
	}
}

void	print_end_simulation(t_table *table, int end, int i)
{
	pthread_mutex_lock(&(table->end_mutex));
	pthread_mutex_lock(&(table->print_mutex));
	table->end_simulation = 1;
	if (end == DEAD_PH)
	{
		printf("\033[31m%i %i died\033[0m\n", \
			get_current_time_ms() - table->start_time_simulation, \
			table->philosophers[i].id);
	}
	if (end == FULL_PH)
		printf(FULL_PHILOS);
	pthread_mutex_unlock(&(table->print_mutex));
	pthread_mutex_unlock(&(table->end_mutex));
}

int	ft_usleep(int milliseconds)
{
	int	end_time;

	end_time = 0;
	end_time = get_current_time_ms() + milliseconds;
	while (get_current_time_ms() < end_time)
		usleep(200);
	return (0);
}

/**
 * get the number of philosophers who have reach
 * the minim amount of meals required
 */
int	count_fully_fed_philos(t_table *table)
{
	int	philo_full;

	pthread_mutex_lock(&(table->philos_full_mutex));
	philo_full = table->philos_fed_full;
	pthread_mutex_unlock(&(table->philos_full_mutex));
	return (philo_full);
}
