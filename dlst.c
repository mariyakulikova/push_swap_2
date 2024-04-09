/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:28:34 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/02 20:53:02 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlst	*dlst_new(int value)
{
	t_dlst	*new;

	new = (t_dlst*)malloc(sizeof(t_dlst));
	if (!new)
		exit(EXIT_FAILURE);
	new->next = NULL;
	new->prev = NULL;
	new->value = value;
	return (new);
}


