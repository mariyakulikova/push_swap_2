/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:37:55 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/24 14:55:05 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	rotate_stack(t_stack *stack)
{
	t_dlst	*prev_head;
	t_dlst	*prev_last;

	prev_head = stack->head;
	prev_last = stack->last;
	stack->head = prev_head->next;
	stack->head->prev = NULL;
	stack->last->next = prev_head;
	prev_head->next = NULL;
	prev_head->prev = stack->last;
	stack->last = prev_head;
	set_stack_idx(stack);
}

void	ra(t_stack *a)
{
	if (a && a->size > 1)
		rotate_stack(a);
}

void	rb(t_stack *b)
{
	if (b && b->size > 1)
		rotate_stack(b);
}

void	rr(t_stack *a, t_stack *b)
{
	if (!a && !b)
		return ;
	if (a && a->size > 1)
		rotate_stack(a);
	if (b && b->size > 1)
		rotate_stack(b);
}
