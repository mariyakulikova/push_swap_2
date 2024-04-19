/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:22:37 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/19 21:42:34 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_dlst	*evaluate_targets_and_get_costless(t_stack *stack1, t_stack *stack2)
{
	t_dlst	*curr1;
	t_dlst	*best;

	curr1 = stack1->head;
	best = curr1;
	while (curr1)
	{
		curr1->target = find_target(stack2, curr1->alias);
		curr1->cost = curr1->moves + curr1->target->moves + 1;
		if (curr1->cost == 1)
			return (curr1);
		if (best->cost > curr1->cost)
			best = curr1;
		curr1 = curr1->next;
	}
	return (best);
}

static void print_stacks(t_ps *params)
{
	printf("<-------------------------------------------------------->\n");
	test(params->a, "a");
	printf("<-------------------------------------------------------->\n");
	test(params->b, "b");
	// printf("stack B last - %d\n", params->b->last->alias);
	printf("<-------------------------------------------------------->\n");
}

void	push_swap(t_ps *params)
{
	t_dlst	*node;
	t_dlst	*target;

	// print_stacks(params);
	while (params->a->size > 3)
		pb(params->b, params->a);
	sort3(params->a, 'a');
	while (params->b->size > 0)
	{
		node = evaluate_targets_and_get_costless(params->b, params->a);
		// print_stacks(params);
		target = node->target;
		if (node ->moves > 0)
			move_stack_b(params->b, node);
		if (target->moves > 0)
			move_stack_a(params->a, target);
		pa(params->a, params->b);
	}
	while (params->a->head->alias != params->a->min->alias)
		move_stack_a(params->a, params->a->min);
	// print_stacks(params);
}
