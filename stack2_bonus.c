/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:38:03 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/24 14:55:57 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_stack(t_stack *stack)
{
	free_dlst_list(stack->head);
	free(stack);
}

void	set_stack_idx(t_stack *stack)
{
	int		i;
	int		median;
	t_dlst	*curr;

	i = 0;
	median = stack->size / 2;
	curr = stack->head;
	while (curr)
	{
		curr->curr_idx = i;
		if (i <= median)
		{
			curr->direction = 1;
			curr->moves = i;
		}
		else
		{
			curr->direction = -1;
			curr->moves = stack->size - i;
		}
		i++;
		curr = curr->next;
	}
}

void	move_stack_a(t_stack *a, t_dlst *node)
{
	int		i;
	int		moves;
	void	(*f)(t_stack *stack);

	i = 0;
	moves = node->moves;
	if (node->direction == 1)
		f = ra;
	else
		f = rra;
	while (i < moves)
	{
		f(a);
		i++;
	}
}

void	move_stack_b(t_stack *b, t_dlst *node)
{
	int		i;
	int		moves;
	void	(*f)(t_stack *stack);

	i = 0;
	moves = node->moves;
	if (node->direction == 1)
		f = rb;
	else
		f = rrb;
	while (i < moves)
	{
		f(b);
		i++;
	}
}

void	move_both_stack(t_stack *a, t_stack *b, t_dlst *node, t_dlst *target)
{
	int		i;
	int		moves;
	void	(*f)(t_stack *a, t_stack *b);

	i = 0;
	if (node->moves < target->moves)
		moves = node->moves;
	else
		moves = target->moves;
	if (node->direction == 1)
		f = rr;
	else
		f = rrr;
	while (i < moves)
	{
		f(a, b);
		i++;
	}
}
