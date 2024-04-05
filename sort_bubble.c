/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bubble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:48:28 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/05 20:50:26 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_solved(t_state state, int smallest);
static void	move_to_closest_swap(t_state *state, int min, t_list **solution);

t_list	*bubble_sort(t_state state)
{
	int		smallest;
	t_list	*solution;

	smallest = get_smallest_a(state);
	solution = NULL;
	while (!is_solved(state, smallest))
	{
		move_to_closest_swap(&state, smallest, &solution);
		swap_a(&state, &solution);
	}
	move_a_to_n(&state, smallest, &solution);
	return (solution);
}

static int	is_solved(t_state state, int smallest)
{
	unsigned int	i;

	i = 0;
	while (i < state.size - 1)
	{
		if (state.stacks[i + 1] != smallest)
			if (state.stacks[i] > state.stacks[i + 1])
				return (0);
		i++;
	}
	return (1);
}

static void	move_to_closest_swap(t_state *state, int min, t_list **solution)
{
	int	n_r;
	int	n_rr;
	int	*st;
	int	sz;

	st = state->stacks;
	sz = state->size;
	n_r = 0;
	while ((st[n_r] < st[n_r + 1] || st[n_r] == min || st[n_r + 1] == min)
		&& n_r < sz - 1)
		n_r++;
	if (st[sz - 1] > st[0] && st[sz - 1] != min && st[0] != min)
		n_rr = 1;
	else
	{
		n_rr = 2;
		while ((st[sz - n_rr] < st[sz - n_rr + 1] || st[n_rr] == min || st[n_rr
					+ 1] == min) && n_rr < sz - 1)
			n_rr++;
	}
	if (n_r < n_rr)
		repeat(&rot_a, n_r, state, solution);
	else
		repeat(&rrot_a, n_rr, state, solution);
}
