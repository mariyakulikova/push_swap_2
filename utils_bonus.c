/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:14:22 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/24 14:56:22 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_split(char **s)
{
	int	i;

	i = 0;
	while (*(s + i))
	{
		free(*(s + i));
		i++;
	}
	free(s);
}

int	split_size(char **s)
{
	int	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

int	free_and_exit(t_ps *params, int exit_status)
{
	if (!params)
		exit(exit_status);
	if (params->a)
		free_stack(params->a);
	if (params->b)
		free_stack(params->b);
	free(params);
	exit(exit_status);
}

long	alpha_to_long(char *nptr)
{
	long	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	while (*nptr == '\f' || *nptr == '\n' || *nptr == '\r' \
	|| *nptr == '\t' || *nptr == '\v' || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr && ft_isdigit(*nptr))
		nbr = nbr * 10 + (*nptr++ - '0');
	return (nbr * sign);
}

int	get_alias(int *tab, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (*(tab + i) == value)
			break ;
		i++;
	}
	return (i);
}
