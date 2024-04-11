/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cost_based.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:53:24 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/10 15:56:48 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_COST_BASED_H
# define SORT_COST_BASED_H

# include "push_swap.h"

typedef struct s_cost_move
{
	int	a_moves;
	int	b_moves;
	int	size;
	int	breaking_point;
	int	best_cost;
}		t_cost_move;

void	do_cost_based_move(t_state *state, t_list **solution);
void	estimate_n_update_cost(t_cost_move *cur, t_cost_move *best);

#endif