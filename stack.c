/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:52:42 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/10 21:55:31 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_dlst *head)
{
	t_dlst	*curr;

	curr = head;
	while (head && curr->next)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	stack_size(t_dlst *head)
{
	int		i;
	t_dlst	*curr;

	i = 0;
	curr = head;
	while (head && curr)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}

t_stack	*stack_init()
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->max = 0;
	stack->min = 0;
	stack->size = 0;
	return (stack);
}

t_dlst	*get_stack(char **tab, int size)
{
	// int		value;
	// t_dlst	*head;
	// t_dlst	*curr;
	// t_dlst	*next;

	for (int i = 0; i < size; i++)
		printf("%s\n", *(tab + i));
	return NULL;
}
