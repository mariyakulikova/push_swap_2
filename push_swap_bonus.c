/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:22:37 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/24 14:55:37 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	calc_cost(t_dlst *node, t_dlst *target)
{
	int	cost;

	cost = 1;
	if (node->direction == target->direction)
	{
		if (node->moves > target->moves)
			cost += node->moves;
		else
			cost += target->moves;
	}
	else
		cost += (node->moves + target->moves);
	return (cost);
}

static t_dlst	*evaluate_targets_and_get_cheap(t_stack *s1, t_stack *s2)
{
	t_dlst	*curr1;
	t_dlst	*best;

	curr1 = s1->head;
	best = curr1;
	while (curr1)
	{
		curr1->target = find_target(s2, curr1->alias);
		curr1->cost = calc_cost(curr1, curr1->target);
		if (curr1->cost == 1)
			return (curr1);
		if (best->cost > curr1->cost)
			best = curr1;
		curr1 = curr1->next;
	}
	return (best);
}

void	push_swap(t_ps *params)
{
	t_dlst	*node;
	t_dlst	*target;

	while (params->a->size > 3)
		pb(params->b, params->a);
	sort3(params->a, 'a');
	while (params->b->size > 0)
	{
		node = evaluate_targets_and_get_cheap(params->b, params->a);
		target = node->target;
		if ((node->direction == target->direction) \
			&& (node->moves > 0 && target->moves > 0))
			move_both_stack(params->a, params->b, node, target);
		if (node->moves > 0)
			move_stack_b(params->b, node);
		if (target->moves > 0)
			move_stack_a(params->a, target);
		pa(params->a, params->b);
	}
	while (params->a->head->alias != params->a->min->alias)
		move_stack_a(params->a, params->a->min);
}
