/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:48:28 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/30 17:45:07 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_state *head)
{
	t_solution	*solution;

	solution = create_simple_solution(head);
	solution = optimize_solution(solution);
	print_solution(solution);
	clear_solution(solution);
}

int	main(int ac, char **av)
{
	t_state	*head;

	if (ac > 1)
	{
		head = parse_args(ac - 1, av);
		if (!head)
			ft_putendl_fd("Error", 3);
		else
		{
			push_swap(head);
		}
	}
	return (0);
}
