/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:12:40 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/14 21:52:03 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_first_2_elem(t_stack *stack)
{
	t_dlst	*temp;

	if (stack->size <= 1)
		return ;
	temp = stack->head->next;
	stack->head->prev = temp;
	stack->head->next = temp->next;
	stack->head->next->prev = stack->head;
	temp->next = stack->head;
	temp->prev = NULL;
	stack->head = temp;
}

void	put_at_top(t_stack *stack1, t_stack *stack2)
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
