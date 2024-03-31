/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_simple_solution.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:34:13 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/31 20:16:03 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_solution	*create_first_node(t_state *head);
int			is_state_sorted(t_state state);

t_solution	*create_simple_solution(t_state *head)
{
	t_solution	*solution;

	solution = create_first_node(head);
	if (is_state_sorted(solution->state))
		return (solution);
	return (apply_simple_strategy(solution));
}

t_solution	*create_first_node(t_state *head)
{
	t_solution	*solution;

	solution = malloc(sizeof(t_solution));
	check_malloc(solution);
	solution->state = *head;
	solution->instr[0] = 0;
	solution->next = NULL;
	return (solution);
}

int	is_state_sorted(t_state state)
{
	int	i;

	i = 0;
	while (i < state.size - 1)
	{
		if (state.stacks[i] > state.stacks[i + 1])
			return (0);
		i++;
	}
	return (1);
}
