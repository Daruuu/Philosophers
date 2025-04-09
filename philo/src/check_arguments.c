/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:56:13 by dasalaza          #+#    #+#             */
/*   Updated: 2025/04/09 11:17:14 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/*
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
*/
int	ft_atoi(const char *str)
{
	long	result;
	int		sign;

	sign = 1;
	result = 0;
	while (*str && (*str == ' ' || (*str >= 9 && *str <= 13)))
		str ++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str ++;
	}
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			result = (result * 10) + (*str - '0');
		else
			return (-1);
		if (result > INT_MAX)
			return (-1);
		str++;
	}
	return (sign * (int) result);
}

/**
 * @brief Validates the command-line arguments.
 *
 * Converts each argument to an integer using `ft_atoi()`
 * and checks for validity.
 *
 * @param ac Number of arguments received.
 * @param av Array of strings containing the arguments.
 *
 * @return int 0 if all arguments are valid, or -1 if at least one is invalid.
 */
int	check_valid_args(int ac, char **av)
{
	int	i;
	int	tmp;

	i = 1;
	while (i < ac)
	{
		tmp = (int) ft_atoi(av[i]);
		if (tmp <= 0)
			return (1);
		i ++;
	}
	return (0);
}
