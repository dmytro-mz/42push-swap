/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack_to_n.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:48:28 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/06 11:30:05 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a_to_n(t_state *state, int n, t_list **solution)
{
	int	n_r;
	int	n_rr;
	int	*st;
	int	sz;

	st = state->stacks;
	sz = state->size;
	n_r = 0;
	while (st[state->break_point + n_r] != n && (int)state->break_point
		+ n_r < sz)
		n_r++;
	n_rr = 1;
	while (st[sz - n_rr] != n && sz - n_rr >= (int)state->break_point)
		n_rr++;
	if (n_r < n_rr)
		repeat(&rot_a, n_r, state, solution);
	else
		repeat(&rrot_a, n_rr, state, solution);
}

int	estimate_move_a_to_n(t_state *state, int n)
{
	int	n_r;
	int	n_rr;
	int	*st;
	int	sz;

	st = state->stacks;
	sz = state->size;
	n_r = 0;
	while (st[state->break_point + n_r] != n && (int)state->break_point
		+ n_r < sz)
		n_r++;
	n_rr = 1;
	while (st[sz - n_rr] != n && sz - n_rr >= (int)state->break_point)
		n_rr++;
	if (n_r < n_rr)
		return (n_r);
	else
		return (n_rr);
}
