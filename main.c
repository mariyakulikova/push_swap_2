/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:32:37 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/14 17:45:45 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**get_norm_data(char **argv, int argc)
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

static int	is_duplicate(int **tab, int size, int value)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (*(*tab + i) == value)
			return (1);
	}
	return (0);
}

static int	set_value(long *value, char *data)
{
	int	i;

	i = 0 ;
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

static int	set_tab(int **tab, char **argv, int argc)
{
	int		i;
	char	**data;
	int		size;
	long	value;

	data = get_norm_data(argv, argc);
	if (!data)
		return (-1);
	size = (split_size(data));
	*tab = (int *)malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
	{
		if (set_value(&value, *(data + i)))
			return (-1);
		if (is_duplicate(tab, i, value))
			return -1;
		*(*tab + i) = (int)value;
	}
	free_split(data);
	return (size);
}

int	main(int argc, char **argv)
{
	t_ps	*params;
	int		*tab;
	int		size;

	if (argc == 1 || (argc == 2 && !**(argv + 1)))
		return (0);
	size = set_tab(&tab, argv, argc);
	if (size == -1)
	{
		write(2, ERR, ft_strlen(ERR));
		free(tab);
		return (EXIT_FAILURE);
	}
	params = params_init();
	if (!params)
		return (EXIT_FAILURE);
	set_stack_params(params, tab, size);
	free(tab);
	if (params->a->size > 1 && !is_stack_sorted(params->a->head))
		sort(params);
	test(params);
	return (free_and_exit(params, EXIT_SUCCESS));
}
