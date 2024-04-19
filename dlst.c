/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:28:34 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/19 10:26:51 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlst	*dlst_new(int value, int alias)
{
	t_dlst	*new;

	new = (t_dlst*)malloc(sizeof(t_dlst));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->target = NULL;
	new->value = value;
	new->alias = alias;
	new->curr_idx = -1;
	new->direction = 0;
	new->cost = -1;
	new->moves = -1;
	return (new);
}

void	free_dlst_list(t_dlst *head)
{
	t_dlst	*next;

	if (head)
		next = head->next;
	while (head)
	{
		free(head);
		head = next;
		if (next)
			next = next->next;
	}
}

t_dlst	*dlstlast(t_dlst *head)
{
	t_dlst	*curr;

	if (!head)
		return (NULL);
	curr = head;
	while (curr->next)
		curr = curr->next;
	return (curr);
}

t_dlst	*find_target(t_stack *stack, int alias)
{
	t_dlst	*curr;
	int		i;

	i = 1;
	while (i <= stack->max->alias)
	{
		curr = stack->head;
		while (curr)
		{
			if (alias + i == curr->alias)
				return (curr);
			curr = curr->next;
		}
		i++;
	}
	return (stack->min);
}
