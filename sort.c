/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:31:01 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/17 20:57:22 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (*(tab + j) > *(tab + j + 1))
			{
				temp = *(tab + j);
				*(tab + j) = *(tab + j + 1);
				*(tab + j + 1) = temp;
			}
			j++;
		}
		i++;
	}
}

void	sort3(t_stack *stack, char c)
{
	if (stack->head->value == stack->max->value)
	{
		if (c == 'a')
			ra(stack);
		else
			rb(stack);
	}
	else if (stack->head->next->value == stack->max->value)
	{
		if (c == 'a')
			rra(stack);
		else
			rrb(stack);
	}
	if (stack->head->next->value < stack->head->value)
	{
		if (c == 'a')
			sa(stack);
		else
			sb(stack);
	}

}


