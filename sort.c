/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:31:01 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/15 11:51:16 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_ps *params)
{
	printf("THIS IS TEST\n");
	test(params->a, "a");
	printf("<-------------------------------------------------------->\n");
	// int tab[3] = {7, 8, 9};
	// params->b->head = get_stack(tab, 3);
	// params->b->size = 3;
	// test(params->b);
	ra(params->a);
	// test(params->a, "a");
	printf("<-------------------------------------------------------->\n");
	test(params->a, "a");
}
