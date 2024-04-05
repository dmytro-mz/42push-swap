/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_smallest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:48:28 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/05 19:18:23 by dmoroz           ###   ########.fr       */
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
