/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 20:49:45 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/14 21:50:05 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	write(1, "pa\n", 3);
	if (a && b)
		put_at_top(a, b);
}

void	pb(t_stack *b, t_stack *a)
{
	write(1, "pb\n", 3);
	if (a && b)
		put_at_top(b, a);
}
