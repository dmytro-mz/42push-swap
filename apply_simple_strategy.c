/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_simple_strategy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 10:55:58 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/31 20:16:02 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_smallest_a(t_solution *s);

t_solution	*apply_simple_strategy(t_solution *head)
{
	t_solution	*cur;
	int			smallest;

	cur = head;
	while (!is_a_empty(cur))
	{
		smallest = find_smallest_a(cur);
		while (get_a_head(cur) != smallest)
			cur = rotate_a(cur);
		cur = push_b(cur);
	}
	while (is_b_empty(cur))
		cur = push_a(cur);
	return (head);
}

static int	find_smallest_a(t_solution *s)
{
	int	min;
	int	i;

	i = s->state.break_point + 1;
	min = s->state.stacks[i - 1];
	while (i < s->state.size)
	{
		if (s->state.stacks[i] < min)
			min = s->state.stacks[i];
		i++;
	}
	return (min);
}
