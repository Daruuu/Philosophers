/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:12:41 by dasalaza          #+#    #+#             */
/*   Updated: 2025/03/20 14:32:01 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	init_threads(void)
{
}

int	ft_atoi(char *str)
{
	unsigned int	i;
	int				result;
	int				sign;

	i = 0;
	sign = 1;
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
	return (sign * result);
}

int	check_valid_args(int ac, char **av)
{
	int	i;
	int	tmp;

	i = 0;
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
