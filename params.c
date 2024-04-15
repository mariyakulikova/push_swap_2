/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:31:43 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/15 11:30:23 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
// TODO function generalized
void	set_stack_params(t_ps *params, int *tab, int size)
{
	params->a->head = get_stack(tab, size);
	if (!params->a->head)
		free_and_exit(params, EXIT_FAILURE);
	params->a->last = dlstlast(params->a->head);
	params->a->size = size;
	set_stack_max_min(params->a);
}
