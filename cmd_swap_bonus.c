/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 21:46:02 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/24 14:55:11 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	swap_first_2_elem(t_stack *stack)
{
	t_dlst	*temp;

	temp = stack->head->next;
	stack->head->prev = temp;
	stack->head->next = temp->next;
	stack->head->next->prev = stack->head;
	temp->next = stack->head;
	temp->prev = NULL;
	stack->head = temp;
	set_stack_idx(stack);
}

void	sa(t_stack *a)
{
	if (!a || a->size <= 1)
		return ;
	swap_first_2_elem(a);
}

void	sb(t_stack *b)
{
	if (!b || b->size <= 1)
		return ;
	swap_first_2_elem(b);
}

void	ss(t_stack *a, t_stack *b)
{
	if (!a && !b)
		return ;
	if (a && a->size > 1)
		swap_first_2_elem(a);
	if (b && b->size > 1)
		swap_first_2_elem(b);
}
