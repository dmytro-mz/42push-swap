/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:45:08 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/30 18:20:22 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_state
{
	int					*stacks;
	unsigned int		size;
	unsigned int		break_point;
}						t_state;

typedef struct s_solution
{
	t_state				state;
	char				instr;
	struct s_solution	*next;
}						t_solution;

t_state					*parse_args(int size, char **args);

#endif