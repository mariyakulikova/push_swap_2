/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:48:30 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/17 11:38:46 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**get_norm_data(char **argv, int argc)
{
	char	**tab;
	int		i;

	if (argc == 2)
	{
		tab = ft_split(*(argv + 1), ' ');
		if (!tab)
			return (NULL);
		return (tab);
	}
	tab = (char **)malloc(sizeof(char *) * argc);
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < argc - 1)
	{
		*(tab + i) = ft_strdup(*(argv + 1 + i));
		if (!*(tab + i))
		{
			// TODO free
			return (NULL);
		}
	}
	*(tab + i) = NULL;
	return (tab);
}

int	is_duplicate(int *tab, int size, int value)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (*(tab + i) == value)
			return (1);
	}
	return (0);
}

int	set_value(long *value, char *data)
{
	int	i;

	i = 0 ;
	if (*data == '-')
		i++;
	while (*(data + i))
	{
		if (!ft_isdigit(*(data + i)))
			return (1);
		i++;
	}
	*value = alpha_to_long(data);
	if (*value > INT_MAX || *value < INT_MIN)
		return (1);
	return (0);
}