/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:45:08 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/31 20:16:04 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_state
{
	int				*stacks;
	unsigned int	size;
	unsigned int	break_point;
}					t_state;

typedef struct s_solution
{
	t_state				state;
	char				instr[4];
	struct s_solution	*next;
}						t_solution;

t_state		*parse_args(int size, char **args);
t_solution	*apply_simple_strategy(t_solution *solution);

//operation_push
t_solution	*push_a(t_solution *s);
t_solution	*push_b(t_solution *s);
// operation_rotate
t_solution	*rotate_a(t_solution *s);
t_solution	*rotate_b(t_solution *s);
t_solution	*rotate_ab(t_solution *s);

//is_empty_stack
int			is_a_empty(t_solution *s);
int			is_b_empty(t_solution *s);
//get_stack_head
int			get_a_head(t_solution *s);
int			get_b_head(t_solution *s);

#endif