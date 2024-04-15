/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 20:49:45 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/15 10:44:02 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_at_top(t_stack *stack1, t_stack *stack2)
{
	t_dlst	*head1_prev;
	t_dlst	*head2_prev;

	if (stack2->size == 0)
		return ;
	head1_prev = stack1->head;
	head2_prev = stack2->head;
	stack2->head = head2_prev->next;
	stack2->head->prev = NULL;
	stack1->head->prev = head2_prev;
	stack1->head = head2_prev;
	stack1->head->prev = NULL;
	stack1->head->next = head1_prev;
}

void	pa(t_stack *a, t_stack *b)
{
	if (!b)
		return;
	write(1, "pa\n", 3);
	put_at_top(a, b);
}

void	pb(t_stack *b, t_stack *a)
{
	if (!a)
		return;
	write(1, "pb\n", 3);
	put_at_top(b, a);
}
