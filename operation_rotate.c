/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:48:28 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/05 21:23:06 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_a(t_state *state, t_list **solution)
{
	int	top;

	ft_lstadd_back(solution, ft_lstnew("ra"));
	if (state->size - state->break_point >= 2)
	{
		top = get_a_head(state);
		ft_memmove(state->stacks + state->break_point, state->stacks
			+ state->break_point + 1, (state->size - state->break_point - 1)
			* sizeof(int));
		state->stacks[state->size - 1] = top;
	}
}

void	rot_b(t_state *state, t_list **solution)
{
	int	top;

	ft_lstadd_back(solution, ft_lstnew("rb"));
	if (state->break_point >= 2)
	{
		top = get_b_head(state);
		ft_memmove(state->stacks + 1, state->stacks, (state->break_point - 1)
			* sizeof(int));
		state->stacks[state->break_point - 1] = top;
	}
}

void	rot_ab(t_state *state, t_list **solution)
{
	int	top;

	ft_lstadd_back(solution, ft_lstnew("rr"));
	if (state->size - state->break_point >= 2)
	{
		top = get_a_head(state);
		ft_memmove(state->stacks + state->break_point, state->stacks
			+ state->break_point + 1, (state->size - state->break_point - 1)
			* sizeof(int));
		state->stacks[state->size - 1] = top;
	}
	if (state->break_point >= 2)
	{
		top = get_b_head(state);
		ft_memmove(state->stacks + 1, state->stacks, (state->break_point - 1)
			* sizeof(int));
		state->stacks[state->break_point - 1] = top;
	}
}
