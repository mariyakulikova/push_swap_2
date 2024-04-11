/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:14:22 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/11 13:09:03 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	printf("split size - %d\n", i);
	return (i);
}

int	free_and_exit(t_ps *params, int exit_status, int print_err)
{
	if (print_err)
		write(2, ERR, ft_strlen(ERR));
	if (!params)
		exit(exit_status);
	// TODO free t_dlst
	if (params->a)
		free(params->a);
	if (params->b)
		free(params->b);
	free(params);
	exit(exit_status);
}

// TODO check for not digit characters
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
