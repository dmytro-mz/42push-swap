/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack_to_closest_swap.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:51:36 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/10 15:51:44 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a_to_closest_swap(t_state *state, int n, t_list **solution)
{
	int	n_r;
	int	n_rr;
	int	*st;
	int	sz;
	int	bp;

	st = state->stacks;
	sz = state->size;
	bp = state->break_point;
	n_r = bp;
	while (n_r < sz - 1 && (st[n_r] < st[n_r + 1] || st[n_r] == n || st[n_r
				+ 1] == n))
		n_r++;
	n_r -= bp;
	n_rr = sz - bp - n_r;
	if (n_r < n_rr)
		repeat(&rot_a, n_r, state, solution);
	else
		repeat(&rrot_a, n_rr, state, solution);
}
