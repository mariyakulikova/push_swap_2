/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:32:37 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/24 16:54:05 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	*params;
	int		*tab;
	int		*sorted;
	int		size;

	if (argc == 1 || (argc == 2 && !**(argv + 1)))
		return (0);
	size = set_tabs(&tab, &sorted, argv, argc);
	if (size == -1)
	{
		write(2, ERR, ft_strlen(ERR));
		free(tab);
		// free(sorted);
		return (EXIT_FAILURE);
	}
	params = params_init();
	if (!params)
		return (EXIT_FAILURE);
	set_stack_params(params, tab, sorted, size);
	free(tab);
	free(sorted);
	if (params->a->size > 1 && !is_stack_sorted(params->a->head))
		push_swap(params);
	return (free_and_exit(params, EXIT_SUCCESS));
}
