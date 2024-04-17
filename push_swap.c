/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:22:37 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/17 10:23:06 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_ps *params)
{
	// printf("THIS IS TEST\n");
	test(params->a, "a");
	printf("<-------------------------------------------------------->\n");
	// int tab[3] = {7, 8, 9};
	// params->b->head = get_stack(tab, 3);
	// params->b->size = 3;
	// test(params->b);
	sort3(params->a, 'a');
	printf("<-------------------------------------------------------->\n");
	test(params->a, "a");
}
