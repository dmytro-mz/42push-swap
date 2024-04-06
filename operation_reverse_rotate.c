/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:48:28 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/06 15:32:24 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrot_a(t_state *state, t_list **solution)
{
	int	tail;

	ft_lstadd_back(solution, ft_lstnew("rra"));
	if (state->size - state->break_point >= 2)
	{
		tail = get_a_tail(state);
		ft_memmove(state->stacks + state->break_point + 1, state->stacks
			+ state->break_point, (state->size - state->break_point - 1)
			* sizeof(int));
		state->stacks[state->break_point] = tail;
	}
}

void	rrot_b(t_state *state, t_list **solution)
{
	int	tail;

	ft_lstadd_back(solution, ft_lstnew("rrb"));
	if (state->break_point >= 2)
	{
		tail = get_b_tail(state);
		ft_memmove(state->stacks, state->stacks + 1, (state->break_point - 1)
			* sizeof(int));
		state->stacks[state->break_point - 1] = tail;
	}
}

void	rrot_ab(t_state *state, t_list **solution)
{
	int	tail;

	ft_lstadd_back(solution, ft_lstnew("rrr"));
	if (state->size - state->break_point >= 2)
	{
		tail = get_a_tail(state);
		ft_memmove(state->stacks + state->break_point + 1, state->stacks
			+ state->break_point, (state->size - state->break_point - 1)
			* sizeof(int));
		state->stacks[state->break_point] = tail;
	}
	if (state->break_point >= 2)
	{
		tail = get_b_tail(state);
		ft_memmove(state->stacks, state->stacks + 1, (state->break_point - 1)
			* sizeof(int));
		state->stacks[state->break_point - 1] = tail;
	}
}
