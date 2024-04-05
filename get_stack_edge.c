/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack_edge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:48:28 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/03 16:06:54 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_a_head(t_state *state)
{
	return (state->stacks[state->break_point]);
}

int	get_b_head(t_state *state)
{
	return (state->stacks[state->break_point - 1]);
}

int	get_a_tail(t_state *state)
{
	return (state->stacks[state->size - 1]);
}

int	get_b_tail(t_state *state)
{
	return (state->stacks[0]);
}
