/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ez_pz.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:48:28 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/15 11:22:55 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ez_pz_sort(t_state state)
{
	t_list	*solution;
	int		min;
	int		max;

	solution = NULL;
	while (get_a_size(&state) > 3 && !is_sorted(state))
	{
		min = get_smallest_a(state);
		max = get_largest_a(state);
		if (estimate_move_a_to_n(&state, min) < estimate_move_a_to_n(&state,
				max))
			move_a_to_n(&state, min, &solution);
		else
			move_a_to_n(&state, max, &solution);
		push_b(&state, &solution);
		if (get_b_head(&state) == max)
			rot_b(&state, &solution);
	}
	ft_lstadd_back(&solution, get_best_bubble_solution(&state));
	while (!is_b_empty(state))
		push_a(&state, &solution);
	move_a_to_n(&state, get_smallest_a(state), &solution);
	return (solution);
}
