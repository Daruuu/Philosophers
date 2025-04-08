/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:19:31 by dasalaza          #+#    #+#             */
/*   Updated: 2025/04/08 18:27:57 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	one_philosopher(t_philo *philo)
{
	if (philo->table->total_philos == 1)
	{
		pthread_mutex_lock(philo->fork_left);
		print_states_philos(philo, ONE_PHILO_STR);
		pthread_mutex_unlock(philo->fork_left);
		return (1);
	}
	return (0);
}

void	eat_philos(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	print_states_philos(philo, LEFT_FORK_STR);
	pthread_mutex_lock(philo->fork_right);
	print_states_philos(philo, RIGHT_FORK_STR);
	print_states_philos(philo, EATING);
	pthread_mutex_lock(&(philo->death_mutex));
	philo->time_of_death = get_current_time_ms() + philo->time_to_die;
	pthread_mutex_unlock(&(philo->death_mutex));
	ft_usleep(philo->time_to_eat);
	philo->meals_consumed = philo->meals_consumed + 1;
	if (philo->meals_count >= 0 && philo->meals_count == philo->meals_consumed)
	{
		pthread_mutex_lock(&(philo->table->philos_full_mutex));
		philo->table->philos_fed_full = philo->table->philos_fed_full + 1;
		pthread_mutex_unlock(&(philo->table->philos_full_mutex));
	}
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}

/**
 * Define el **ciclo de vida de cada filósofo**: comer, dormir y pensar,
 * repitiéndose hasta que la simulación finaliza.
 */
void	*routine_philo(void *table_philo)
{
	t_philo	*philo;
	int		end_flag;

	philo = (t_philo *) table_philo;
	end_flag = 0;
	pthread_mutex_lock(&(philo->death_mutex));
	philo->time_of_death = get_current_time_ms() + philo->time_to_die;
	pthread_mutex_unlock(&(philo->death_mutex));
	if (one_philosopher(philo))
		return (NULL);
	if (philo->id % 2 == 1)
		ft_usleep(philo->time_to_eat / 2);
	while (end_flag == 0)
	{
		eat_philos(philo);
		print_states_philos(philo, SLEEPING);
		ft_usleep(philo->time_to_sleep);
		print_states_philos(philo, THINKING);
		pthread_mutex_lock(&(philo->table->end_mutex));
		end_flag = philo->table->end_simulation;
		pthread_mutex_unlock(&(philo->table->end_mutex));
	}
	return (NULL);
}

/**
 * @brief Monitors the simulation state of the philosophers.
 *
 * This function continuously checks two conditions:
 * 1. If any philosopher has exceeded their time to die without eating.
 * 2. If all philosophers have eaten the required number of meals.
 *
 * When either condition is met, the function prints a termination message
 * and ends the simulation loop.
 *
 * @param table Pointer to the shared simulation table structure.
 */
void	monitoring(t_table *table)
{
	int	i;
	int	death_time;

	i = 0;
	while (1)
	{
		if (i == table->total_philos)
			i = 0;
		pthread_mutex_lock(&(table->philosophers[i].death_mutex));
		death_time = table->philosophers[i].time_of_death;
		pthread_mutex_unlock(&(table->philosophers[i].death_mutex));
		if (death_time > 0 && get_current_time_ms() > death_time)
		{
			print_end_simulation(table, DEAD_PH, i);
			break ;
		}
		if ((table->meals_count >= 0 \
			&& count_fully_fed_philos(table) == table->total_philos) \
			|| table->meals_count == 0)
		{
			print_end_simulation(table, FULL_PH, i);
			break ;
		}
		i ++;
	}
}
