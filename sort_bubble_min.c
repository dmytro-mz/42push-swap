/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bubble_min.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:48:28 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/06 10:16:20 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_solved(t_state state, int smallest);

t_list	*bubble_sort_min(t_state state)
{
	int		smallest;
	t_list	*solution;

	smallest = get_smallest_a(state);
	solution = NULL;
	while (!is_solved(state, smallest))
	{
		move_a_to_closest_swap(&state, smallest, &solution);
		swap_a(&state, &solution);
	}
	move_a_to_n(&state, smallest, &solution);
	return (solution);
}

static int	is_solved(t_state state, int smallest)
{
	unsigned int	i;
	unsigned int	ip1;

	i = state.break_point;
	while (i < state.size)
	{
		ip1 = i + 1;
		if (i == state.size - 1)
			ip1 = state.break_point;
		if (state.stacks[ip1] != smallest)
			if (state.stacks[i] > state.stacks[ip1])
				return (0);
		i++;
	}
	return (1);
}
