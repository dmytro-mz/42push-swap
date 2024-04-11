/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_strategy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:06:38 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/11 16:17:16 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_state	get_stack_copy(t_state state);

void	try_strategy(t_state stack, t_list *(*f)(t_state), t_list **best_stack,
		int *best_stack_len)
{
	int		solution_len;
	t_list	*solution;
	t_state	copy;

	copy = get_stack_copy(stack);
	if (copy.stacks)
	{
		solution = (*f)(copy);
		solution_len = ft_lstsize(solution);
		if (solution_len < *best_stack_len)
		{
			free_solution(*best_stack);
			*best_stack = solution;
			*best_stack_len = solution_len;
		}
		else
			free_solution(solution);
		free(copy.stacks);
	}
}

static t_state	get_stack_copy(t_state state)
{
	t_state	copy;

	copy.stacks = malloc(sizeof(int) * state.size);
	if (!copy.stacks)
		return (copy);
	ft_memmove(copy.stacks, state.stacks, state.size * sizeof(int));
	copy.size = state.size;
	copy.break_point = state.break_point;
	return (copy);
}
