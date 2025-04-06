//
// Created by daruuu on 3/27/25.
//

#include "../includes/philosophers.h"

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
