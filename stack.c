/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:52:42 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/10 16:34:39 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_dlst *stack)
{
	t_dlst	*curr;

	curr = stack;
	while (curr->next)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	stack_size(t_dlst *stack)
{
	int		i;
	t_dlst	*curr;

	i = 0;
	curr = stack;
	while (curr)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}

void	stack_init(t_stack *stack)
{
	stack->head = NULL;
	stack->max = 0;
	stack->min = 0;
	stack->size = 0;
}

t_dlst	*get_stack(char **tab, int size)
{
	int		value;
	t_dlst	*head;
	t_dlst	*curr;
	t_dlst	*next;

	value = ft_a
}
