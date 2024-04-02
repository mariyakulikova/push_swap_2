/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:34:50 by mkulikov          #+#    #+#             */
/*   Updated: 2024/04/02 14:45:23 by mkulikov         ###   ########.fr       */
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
	int		max;
	int		min;
	t_dlst	head;
}			t_ps;

#endif
