/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:34:50 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/23 21:26:55 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
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
	int				alias;
	int				curr_idx;
	int				cost;
	int				moves;
	int				direction;
	struct s_dlst	*next;
	struct s_dlst	*prev;
	struct s_dlst	*target;
}			t_dlst;

typedef struct s_stack
{
	t_dlst	*head;
	t_dlst	*last;
	t_dlst	*max;
	t_dlst	*min;
	int		size;
}			t_stack;

typedef struct s_ps
{
	t_stack	*a;
	t_stack	*b;
}			t_ps;

/* cmd_push.c */
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *b, t_stack *a);

/* cmd_rev_rotate.c */
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* cmd_rotate */
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

/* cmd_swap.c */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

/* dlst.c */
t_dlst	*dlst_new(int value, int alias);
void	free_dlst_list(t_dlst *head);
t_dlst	*dlstlast(t_dlst *head);
t_dlst	*find_target(t_stack *head, int alias);

/* params.c */
void	set_stack_params(t_ps *params, int *tab, int *sorted, int size);
t_ps	*params_init(void);

/* push_swap.c */
void	push_swap(t_ps *params);

/* sort.c */
void	bubble_sort(int *tab, int size);
void	sort3(t_stack *stack, char c);

/* stack.c */
int		is_stack_sorted(t_dlst *head);
int		stack_size(t_dlst *head);
t_stack	*stack_init(void);
void	set_stack_max_min(t_stack *stack);
t_dlst	*get_stack(int *tab, int *sorted, int size);

/* stack2.c */
void	free_stack(t_stack *stack);
void	set_stack_idx(t_stack *stack);
void	move_stack_a(t_stack *a, t_dlst *node);
void	move_stack_b(t_stack *b, t_dlst *node);
void	move_both_stack(t_stack *a, t_stack *b, t_dlst *node, t_dlst *target);

/* utils.c */
void	free_split(char **s);
int		split_size(char **s);
int		free_and_exit(t_ps *params, int exit_status);
long	alpha_to_long(char *nptr);
int		get_alias(int *tab, int size, int value);

/* tab_utils.c */
char	**get_norm_data(char **argv, int argc);
int		is_duplicate(int *tab, int size, int value);
int		set_value(long *value, char *data);

/* tab.c */
int		set_tabs(int **tab, int **sorted, char **argv, int argc);

/* test */
void	print_split(char **tab);
void	test(t_stack *stack, char *name);

#endif
