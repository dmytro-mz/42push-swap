/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:48:28 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/05 20:49:08 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_state *state, t_list **solution)
{
	int		tmp;
	t_state	s;

	ft_lstadd_back(solution, ft_lstnew("sa"));
	s = *state;
	if (s.size - s.break_point >= 2)
	{
		tmp = get_a_head(state);
		s.stacks[s.break_point] = s.stacks[s.break_point + 1];
		s.stacks[s.break_point + 1] = tmp;
	}
}

void	swap_b(t_state *state, t_list **solution)
{
	int		tmp;
	t_state	s;

	ft_lstadd_back(solution, ft_lstnew("sb"));
	s = *state;
	if (s.break_point >= 2)
	{
		tmp = get_b_head(state);
		s.stacks[s.break_point - 1] = s.stacks[s.break_point - 2];
		s.stacks[s.break_point - 2] = tmp;
	}
}

void	swap_ab(t_state *state, t_list **solution)
{
	int		tmp;
	t_state	s;

	ft_lstadd_back(solution, ft_lstnew("ss"));
	s = *state;
	if (s.size - s.break_point >= 2)
	{
		tmp = get_a_head(state);
		s.stacks[s.break_point] = s.stacks[s.break_point + 1];
		s.stacks[s.break_point + 1] = tmp;
	}
	if (s.break_point >= 2)
	{
		tmp = get_b_head(state);
		s.stacks[s.break_point - 1] = s.stacks[s.break_point - 2];
		s.stacks[s.break_point - 2] = tmp;
	}
}
