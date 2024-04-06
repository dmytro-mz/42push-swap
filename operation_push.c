/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:48:28 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/06 10:02:37 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_state *state, t_list **solution)
{
	ft_lstadd_back(solution, ft_lstnew("pb"));
	if (state->break_point < state->size)
		state->break_point++;
}

void	push_a(t_state *state, t_list **solution)
{
	ft_lstadd_back(solution, ft_lstnew("pa"));
	if (state->break_point > 0)
		state->break_point--;
}
