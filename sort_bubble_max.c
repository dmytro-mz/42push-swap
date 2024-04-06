/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bubble_max.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:48:28 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/06 10:16:14 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_solved(t_state state, int smallest);
static void	move_to_closest_swap(t_state *state, int min, t_list **solution);

t_list	*bubble_sort_max(t_state state)
{
	int		largest;
	t_list	*solution;

	largest = get_largest_a(state);
	solution = NULL;
	while (!is_solved(state, largest))
	{
		move_to_closest_swap(&state, largest, &solution);
		swap_a(&state, &solution);
	}
	move_a_to_n(&state, get_smallest_a(state), &solution);
	return (solution);
}

static int	is_solved(t_state state, int largest)
{
	unsigned int	i;
	unsigned int	ip1;

	i = 0;
	while (i < state.size)
	{
		ip1 = i + 1;
		if (i == state.size - 1)
			ip1 = 0;
		if (state.stacks[i] != largest)
			if (state.stacks[i] > state.stacks[ip1])
				return (0);
		i++;
	}
	return (1);
}

static void	move_to_closest_swap(t_state *state, int max, t_list **solution)
{
	int	n_r;
	int	n_rr;
	int	*st;
	int	sz;

	st = state->stacks;
	sz = state->size;
	n_r = 0;
	while ((st[n_r] < st[n_r + 1] || st[n_r] == max || st[n_r + 1] == max)
		&& n_r < sz - 1)
		n_r++;
	if (st[sz - 1] > st[0] && st[sz - 1] != max && st[0] != max)
		n_rr = 1;
	else
	{
		n_rr = 2;
		while ((st[sz - n_rr] < st[sz - n_rr + 1] || st[n_rr] == max || st[n_rr
					+ 1] == max) && n_rr < sz - 1)
			n_rr++;
	}
	if (n_r < n_rr)
		repeat(&rot_a, n_r, state, solution);
	else
		repeat(&rrot_a, n_rr, state, solution);
}
