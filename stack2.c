/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:38:03 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/17 09:39:51 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	free_dlst_list(stack->head);
	free(stack);
}

void	set_stack_curr_idx(t_stack *stack)
{
	int		i;
	t_dlst	*curr;

	i = 0;
	curr = stack->head;
	while (curr)
	{
		curr->curr_idx = i;
		i++;
		curr = curr->next;
	}
}
