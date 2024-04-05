/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ez.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:48:28 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/05 20:50:50 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ez_sort(t_state state)
{
	t_list	*solution;
	int		smallest;

	solution = NULL;
	while (!is_a_empty(state) && !is_sorted(state))
	{
		smallest = get_smallest_a(state);
		move_a_to_n(&state, smallest, &solution);
		push_b(&state, &solution);
	}
	while (!is_b_empty(state))
		push_a(&state, &solution);
	return (solution);
}
