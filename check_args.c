/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:48:45 by jrocha-f          #+#    #+#             */
/*   Updated: 2024/08/05 13:48:45 by jrocha-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *nptr)
{
	long int	n;
	int			sign;

	n = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-')
		sign *= -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		n *= 10;
		n += *nptr - '0';
		nptr++;
	}
	return (n * sign);
}

void	ft_error(char **args, int str)
{
	ft_putstr_fd("Error\n", 2);
	if (str == 1)
		free_array(args);
	exit(1);
}

static void	ft_check_duplictes(char **args, int i, int value, int str)
{
	int	h;

	h = 1;
	while (args[i + h] != NULL)
	{
		if (ft_atol(args[i + h]) == value)
			ft_error(args, str);
		h++;
	}
}

static void	ft_check_digit(char **args, int str)
{
	int	i;
	int	h;

	i = 0;
	while (args[i] != NULL)
	{
		h = 0;
		if ((args[i][h] == '-' || args[i][h] == '+')
			&& args[i][h + 1] != '\0')
			h++;
		if (!args[i][0])
			ft_error(args, str);
		while (args[i][h] != '\0')
		{
			if (!ft_isdigit(args[i][h]))
				ft_error(args, str);
			h++;
		}
		i++;
	}
}

void	ft_check_args(char **args, int str)
{
	int		i;
	long	temp;

	i = 0;
	ft_check_digit (args, str);
	while (args[i] != NULL)
	{
		temp = ft_atol(args[i]);
		if (temp > INT_MAX || temp < INT_MIN)
			ft_error(args, str);
		ft_check_duplictes(args, i, temp, str);
		i++;
	}
}
