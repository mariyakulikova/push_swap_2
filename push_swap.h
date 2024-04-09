/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:34:50 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/08 17:52:48 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PIPPUSH_SWAP_HEX_H
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_dlst {
	int				value;
	struct s_dlst	*next;
	struct s_dlst	*prev;
}			t_dlst;

typedef struct s_ps{
	int		a_max;
	int		a_min;
	int		b_max;
	int		b_min;
	int		a_size;
	int		b_size;
	t_dlst	*a;
	t_dlst	*b;
}			t_ps;

t_dlst	*dlst_new(int value);
int		split_size(char **s);
void	free_split(char **s);
int		is_stack_sorted(t_dlst *stack);
int		stack_size(t_dlst *stack);

#endif
