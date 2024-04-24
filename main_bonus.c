/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:25:25 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/24 14:55:20 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	parse_cmd(char *s, t_ps *params)
{
	if (!ft_strcmp(s, "sa\n"))
		sa(params->a);
	else if (!ft_strcmp(s, "sb\n"))
		sb(params->b);
	else if (!ft_strcmp(s, "ss\n"))
		ss(params->a, params->b);
	else if (!ft_strcmp(s, "pa\n"))
		pa(params->a, params->b);
	else if (!ft_strcmp(s, "pb\n"))
		pb(params->b, params->a);
	else if (!ft_strcmp(s, "ra\n"))
		ra(params->a);
	else if (!ft_strcmp(s, "rb\n"))
		rb(params->b);
	else if (!ft_strcmp(s, "rr\n"))
		rr(params->a, params->b);
	else if (!ft_strcmp(s, "rra\n"))
		rra(params->a);
	else if (!ft_strcmp(s, "rrb\n"))
		rrb(params->b);
	else if (!ft_strcmp(s, "rrr\n"))
		rrr(params->a, params->b);
	else
	{
		write(2, ERR, ft_strlen(ERR));
		free_and_exit(params, EXIT_FAILURE);
	}
}

void	checker(t_ps *params)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (ft_strcmp(line, "\n"))
	{
		parse_cmd(line, params);
		line = get_next_line(STDIN_FILENO);
	}
	if (is_stack_sorted(params->a->head))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_ps	*params;
	int		*tab;
	int		*sorted;
	int		size;

	if (argc == 1 || (argc == 2 && !**(argv + 1)))
		return (0);
	size = set_tabs(&tab, &sorted, argv, argc);
	if (size == -1)
	{
		write(2, ERR, ft_strlen(ERR));
		free(tab);
		return (EXIT_FAILURE);
	}
	params = params_init();
	if (!params)
		return (EXIT_FAILURE);
	set_stack_params(params, tab, sorted, size);
	free(tab);
	free(sorted);
	if (params->a->size > 1 && !is_stack_sorted(params->a->head))
		checker(params);
	return (free_and_exit(params, EXIT_SUCCESS));
}
