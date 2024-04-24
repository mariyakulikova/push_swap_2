/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:50:19 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/24 17:13:52 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	set_tab(int **tab, char **argv, int argc)
{
	int		i;
	char	**data;
	int		size;
	long	value;

	data = get_norm_data(argv, argc);
	if (!data)
		return (-1);
	size = split_size(data);
	*tab = (int *)malloc(sizeof(int) * size);
	if (!*tab)
		return (-1);
	i = -1;
	while (++i < size)
	{
		if (set_value(&value, *(data + i)))
		{
			free_split(data);
			return (-1);
		}
		if (is_duplicate(*tab, i, value))
		{
			free_split(data);
			return (-1);
		}
		*((*tab) + i) = (int)value;
	}
	free_split(data);
	return (size);
}

static int	set_sorted_tab(int *tab, int **sorted, int size)
{
	int	i;

	*sorted = (int *)malloc(sizeof(int) * size);
	if (!*sorted)
		return (-1);
	i = 0;
	while (i < size)
	{
		*((*sorted) + i) = *(tab + i);
		i++;
	}
	bubble_sort(*sorted, size);
	return (size);
}

int	set_tabs(int **tab, int **sorted, char **argv, int argc)
{
	int	size;

	size = set_tab(tab, argv, argc);
	if (size == -1)
		return (-1);
	size = set_sorted_tab(*tab, sorted, size);
	if (size == -1)
	{
		free(tab);
		return (-1);
	}
	return (size);
}
