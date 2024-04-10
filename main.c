/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:32:37 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/10 21:57:10 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid(int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && !**(argv + 1)))
		return (0);
	return (1);
}

static t_ps	*params_init()
{
	t_ps	*params;

	params = (t_ps *)malloc(sizeof(t_ps));
	if (!params)
		my_exit(NULL, EXIT_FAILURE);
	params->a = stack_init();
	params->b = stack_init();
	if (!params->a || !params->b)
		my_exit(params, EXIT_FAILURE);
	return (params);
}

void	test(t_ps *params)
{
	t_dlst	*curr;

	curr = params->a->head;
	while (curr)
	{
		printf("%d\n", curr->value);
		curr = curr->next;
	}
}

int	main(int argc, char **argv)
{
	t_ps	*params;
	char	**split;

	if (!is_valid(argc, argv))
		return (0);
	params = params_init();
	if (argc == 2)
	{
		split = ft_split(*(argv + 1), ' ');
		params->a->head = get_stack(split, split_size(split));
		free_split(split);
	}
	else
		params->a->head = get_stack(argv + 1, argc - 1);
	// if (params->a->head && params->a->size > 1 && !is_stack_sorted(params->a->head))
	sort(params);
	// test(params);
	return (EXIT_SUCCESS);
}
