#include "../includes/philosophers.h"

/**
 * @param philo
 * @param str_state 
 */
void	print_states_philos(t_philo *philo, char *str_state)
{
	int	end;
	int	get_time;

	pthread_mutex_lock(&(philo->table->end_mutex));
	end = philo->table->simulation_ended;
	pthread_mutex_lock(&(philo->table->print_mutex));
	if (end == 0)
	{
		get_time =  get_current_time_ms() - philo->table->simulation_start_time;
		printf("%i %i %s\n", get_time, philo->id, str_state);
		pthread_mutex_unlock(&(philo->table->end_mutex));
		pthread_mutex_unlock(&(philo->table->print_mutex));
	}
}
