//
// Created by daruuu on 4/1/25.
//

#include "../includes/philosophers.h"

int	one_philosopher(t_philo *philo)
{
	if (philo->table->total_philos == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_states_philos(philo, ONE_PHILO_STR);
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	return (0);
}

void	eat_philos(t_philo *philo)
{

}