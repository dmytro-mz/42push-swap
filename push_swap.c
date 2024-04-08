/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:48:28 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/08 21:47:31 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		try_strategy(t_state stack, t_list *(*f)(t_state),
					t_list **best_stack, int *best_stack_len);
static void		print_solution(t_list *best);
static t_state	get_stack_copy(t_state state);

int	main(int ac, char **av)
{
	t_state	stack;
	t_list	*best;
	int		best_len;

	if (ac > 1)
	{
		stack = parse_args(ac - 1, av + 1);
		if (!is_sorted(stack))
		{
			best = NULL;
			best_len = INT_MAX;
			try_strategy(stack, &bubble_sort_min, &best, &best_len);
			try_strategy(stack, &bubble_sort_max, &best, &best_len);
			try_strategy(stack, &ez_sort, &best, &best_len);
			try_strategy(stack, &ez_pz_sort, &best, &best_len);
			// exit(44); // TODO
			print_solution(best);
		}
	}
	return (0);
}

static void	try_strategy(t_state stack, t_list *(*f)(t_state),
		t_list **best_stack, int *best_stack_len)
{
	int		solution_len;
	t_list	*solution;
	t_state	copy;

	copy = get_stack_copy(stack);
	solution = (*f)(copy);
	solution_len = ft_lstsize(solution);
	// #include "ft_printf.h" // TODO
	// ft_printf("%d\n", solution_len); // TODO
	if (solution_len < *best_stack_len)
	{
		*best_stack = solution;
		*best_stack_len = solution_len;
	}
	free(copy.stacks);
}

static t_state	get_stack_copy(t_state state)
{
	t_state	copy;

	copy.stacks = malloc(sizeof(int) * state.size);
	// check malloc
	ft_memmove(copy.stacks, state.stacks, state.size * sizeof(int));
	copy.size = state.size;
	copy.break_point = state.break_point;
	return (copy);
}

static void	print_solution(t_list *best)
{
	while (best)
	{
		ft_putendl_fd(best->content, 1);
		best = best->next;
	}
}
