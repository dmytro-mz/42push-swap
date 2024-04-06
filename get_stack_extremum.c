/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack_extremum.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:48:28 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/06 10:21:21 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_smallest_a(t_state state)
{
	int				min;
	unsigned int	i;

	i = state.break_point;
	min = state.stacks[i++];
	while (i < state.size)
	{
		if (state.stacks[i] < min)
			min = state.stacks[i];
		i++;
	}
	return (min);
}

int	get_largest_a(t_state state)
{
	int				max;
	unsigned int	i;

	i = state.break_point;
	max = state.stacks[i++];
	while (i < state.size)
	{
		if (state.stacks[i] > max)
			max = state.stacks[i];
		i++;
	}
	return (max);
}
