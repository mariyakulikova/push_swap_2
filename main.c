/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:32:37 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/11 17:56:43 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid(int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && !**(argv + 1)))
		return (0);
	return (1);
}

t_ps	*params_init()
{
	t_ps	*params;

	params = (t_ps *)malloc(sizeof(t_ps));
	if (!params)
		return (NULL);
	params->a = stack_init();
	params->b = stack_init();
	if (!params->a || !params->b)
	{
		free(params);
		return (NULL);
	}
	return (params);
}

void	set_stack_params(t_ps *params, char **split, int size)
{
	params->a->head = get_stack(split, size);
	if (!params->a->head)
		free_and_exit(params, EXIT_FAILURE, 0);
	params->a->size = size;
	set_stack_max_min(params->a);
}

void	test(t_ps *params)
{
	t_dlst	*curr;

	curr = params->a->head;
	while (curr)
	{
		printf("curr - %d, prev - %d, next - %d\n", curr->value, curr->prev ? curr->prev->value : -666, curr->next ? curr->next->value : -666);
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
	if (!params)
		return (EXIT_FAILURE);
	if (argc == 2)
	{
		split = ft_split(*(argv + 1), ' ');
		set_stack_params(params, split, split_size(split));
		free_split(split);
	}
	else
		set_stack_params(params, argv + 1, argc - 1);
	if (params->a->size > 1 && !is_stack_sorted(params->a->head))
		sort(params);
	test(params);
	return (free_and_exit(params, EXIT_FAILURE, 0));
}
