/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:48:28 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/11 16:15:24 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_solution(t_list *best);

int	main(int ac, char **av)
{
	t_state	stack;
	t_list	*best;
	int		best_len;

	if (ac > 1)
	{
		stack = parse_args(ac - 1, av + 1);
		best = NULL;
		if (!is_sorted(stack))
		{
			best_len = INT_MAX;
			if (stack.size < 20)
			{
				try_strategy(stack, &bubble_sort_min, &best, &best_len);
				try_strategy(stack, &bubble_sort_max, &best, &best_len);
				try_strategy(stack, &ez_sort, &best, &best_len);
				try_strategy(stack, &ez_pz_sort, &best, &best_len);
			}
			try_strategy(stack, &cost_based_sort, &best, &best_len);
		}
		print_solution(best);
		free(stack.stacks);
		free_solution(best);
	}
	return (0);
}

static void	print_solution(t_list *best)
{
	while (best)
	{
		ft_putendl_fd(best->content, 1);
		best = best->next;
	}
}
