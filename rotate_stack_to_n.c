/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack_to_n.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:48:28 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/05 20:50:14 by dmoroz           ###   ########.fr       */
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
	n_r = state->break_point;
	while (st[n_r] != n && n_r < sz)
		n_r++;
	n_rr = 1;
	while (st[sz - n_rr] != n && sz - n_rr >= (int)state->break_point)
		n_rr++;
	if (n_r < n_rr)
		repeat(&rot_a, n_r, state, solution);
	else
		repeat(&rrot_a, n_rr, state, solution);
}
