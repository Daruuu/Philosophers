//
// Created by daruuu on 3/27/25.
//
#include "../includes/philosophers.h"

int	get_current_time_ms(void)
{
	struct timeval	tv;
	int				milliseconds;

	gettimeofday(&tv, NULL);
	milliseconds = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (milliseconds);
}
