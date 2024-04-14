/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:12:40 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/14 20:41:36 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_first_2_elem(t_stack *stack)
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

void	sa(t_stack *a)
{
	write(1, "sa\n", 3);
	if (a)
		swap_first_2_elem(a);
}

void	sb(t_stack *b)
{
	write(1, "sb\n", 3);
	if (b)
		swap_first_2_elem(b);
}

void	ss(t_stack *a, t_stack *b)
{
	write(1, "ss\n", 3);
	if (a)
		swap_first_2_elem(a);
	if (b)
		swap_first_2_elem(b);
}

