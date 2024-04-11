/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:28:34 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/11 22:17:54 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlst	*dlst_new(int value)
{
	t_dlst	*new;

	new = (t_dlst*)malloc(sizeof(t_dlst));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->value = value;
	return (new);
}

void	free_dlst(t_dlst *head)
{
	t_dlst	*next;
	if (head)
		next = head->next;
	while (head)
	{
		free(head);
		head = next;
		next = next->next;
	}
}
