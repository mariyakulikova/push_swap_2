/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 21:46:02 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/17 12:30:31 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	set_stack_curr_idx(stack);
}

void	sa(t_stack *a)
{
	if (!a || a-> size <= 1)
		return ;
	write(1, "sa\n", 3);
	swap_first_2_elem(a);
}

void	sb(t_stack *b)
{
	if (!b  || b-> size <= 1)
		return ;
	write(1, "sb\n", 3);
	swap_first_2_elem(b);
}

void	ss(t_stack *a, t_stack *b)
{
	if (!a && !b)
		return ;
	write(1, "ss\n", 3);
	if (a && a->size > 1)
		swap_first_2_elem(a);
	if (b && b->size > 1)
		swap_first_2_elem(b);
}
