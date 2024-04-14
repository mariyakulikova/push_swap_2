/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 21:46:02 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/14 21:46:29 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
