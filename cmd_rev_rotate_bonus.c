/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rev_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:10:56 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/24 14:54:59 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	rev_rotate_stack(t_stack *stack)
{
	t_dlst	*prev_head;
	t_dlst	*prev_last;

	prev_head = stack->head;
	prev_last = stack->last;
	stack->last = prev_last->prev;
	stack->last->next = NULL;
	prev_head->prev = prev_last;
	prev_last->next = prev_head;
	stack->head = prev_last;
	stack->head->prev = NULL;
	set_stack_idx(stack);
}

void	rra(t_stack *a)
{
	if (a && a->size > 1)
		rev_rotate_stack(a);
}

void	rrb(t_stack *b)
{
	if (b && b->size > 1)
		rev_rotate_stack(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	if (!a && !b)
		return ;
	if (a && a->size > 1)
		rev_rotate_stack(a);
	if (b && b->size > 1)
		rev_rotate_stack(b);
}
