/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:56:58 by dasalaza          #+#    #+#             */
/*   Updated: 2025/04/08 17:57:00 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	get_current_time_ms(void)
{
	struct timeval	tv;
	int				milliseconds;

	gettimeofday(&tv, NULL);
	milliseconds = tv.tv_sec * 1000 + (tv.tv_usec / 1000);
	return (milliseconds);
}
