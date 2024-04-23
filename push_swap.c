/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:22:37 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/22 21:54:56 by mkulikov         ###   ########.fr       */
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

static t_dlst	*evaluate_nodes_and_get_costless(t_stack *a, int min_alias, int max_alias)
{
	t_dlst	*curr;
	t_dlst	*best;

	curr = a->head;
	best = curr;
	while (curr)
	{
		if (curr->alias >= min_alias && curr->alias < max_alias)
		{
			curr-> cost = 1 + curr->moves;
			if (best->cost > curr->cost)
				best = curr;
		}
		curr = curr->next;
	}
	return (best);
}

static void	push_by_chunk(t_ps *params)
{
	int		chunks;
	int		chunck_size;
	int		i;
	int		j;
	t_dlst	*node;

	chunks = 10;
	chunck_size = params->a->size / chunks;
	i = 0;
	while (params->a->size > 3 && i < chunks)
	{
		j = 0;
		while (j < chunck_size)
		{
			node = evaluate_nodes_and_get_costless(params->a, i * chunck_size, (i + 1) * chunck_size);
			printf("alias - %d, curr_idx - %d, moves - %d\n", node->alias, node->curr_idx, node->moves);
			if (node->moves > 0)
				move_stack_a(params->a, node);
			pb(params->b, params->a);
			j++;
		}
		i++;
	}
}

void	push_swap(t_ps *params)
{
	t_dlst	*node;
	t_dlst	*target;

	// if (params->a->size <= 100)
	// {
	// 	while (params->a->size > 3)
	// 		pb(params->b, params->a);
	// }
	// else
	push_by_chunk(params);
	sort3(params->a, 'a');
	while (params->b->size > 0)
	{
		node = evaluate_targets_and_get_costless(params->b, params->a);
		target = node->target;
		if (node ->moves > 0)
			move_stack_b(params->b, node);
		if (target->moves > 0)
			move_stack_a(params->a, target);
		pa(params->a, params->b);
	}
	while (params->a->head->alias != params->a->min->alias)
		move_stack_a(params->a, params->a->min);
}
