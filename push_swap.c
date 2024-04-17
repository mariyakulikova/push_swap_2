/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:22:37 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/17 20:45:19 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_targets(t_stack *stack1, t_stack *stack2)
{
	t_dlst	*curr1;

	curr1 = stack1->head;
	while (curr1)
	{
		curr1->target = find_target(curr1, stack2, curr1->alias);
		curr1 = curr1->next;
	}
}

void	push_swap(t_ps *params)
{
	// printf("THIS IS TEST\n");
	test(params->a, "a");

	printf("<-------------------------------------------------------->\n");
	// int tab[3] = {7, 8, 9};
	// params->b->head = get_stack(tab, tab, 3);
	// params->b->size = 3;
	// test(params->b, "b");
	while (params->a->size > 3)
		pb(params->b, params->a);
	sort3(params->a, 'a');
	set_targets(params->b, params->a);
	printf("<-------------------------------------------------------->\n");
	test(params->a, "a");
	printf("<-------------------------------------------------------->\n");
	test(params->b, "b");
}
