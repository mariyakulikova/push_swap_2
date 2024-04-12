/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:34:50 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/12 22:07:05 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PIPPUSH_SWAP_HEX_H
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

# define ERR "Error\n"

typedef struct s_dlst
{
	int				value;
	struct s_dlst	*next;
	struct s_dlst	*prev;
}			t_dlst;

typedef struct s_stack
{
	t_dlst	*head;
	int		max;
	int		min;
	int		size;
}			t_stack;

typedef struct s_ps
{
	t_stack	*a;
	t_stack	*b;
}			t_ps;

t_dlst	*dlst_new(int value);
int		split_size(char **s);
void	free_split(char **s);
long	alpha_to_long(char *nptr);
int		is_stack_sorted(t_dlst *head);
int		stack_size(t_dlst *head);
void	free_dlst(t_dlst *head);
t_stack	*stack_init();
void	set_stack_max_min(t_stack *stack);
int		free_and_exit(t_ps *params, int exit_status, int print_err);
t_dlst	*get_stack(int *tab, int size);
void	sort(t_ps *params);

/* params.c */
void	set_stack_params(t_ps *params, int *tab, int size);
t_ps	*params_init();

/* test */
void	print_split(char **tab);
void	test(t_ps *params);

#endif
