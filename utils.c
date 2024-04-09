/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:14:22 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/08 18:41:48 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **s)
{
	int	i;

	i = 0;
	while (*(s + i))
	{
		free(s + i);
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



long	ft_atoi(const char *nptr)
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
