/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_solution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 11:15:03 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/31 18:34:02 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#ifndef N_STEPS
# define N_STEPS 7
#endif

static void	init(int *n_sub, t_solution **start, t_solution ***prev,
				t_solution *head);

t_solution	*optimize_solution(t_solution *head)
{
	int			n_imp;
	t_solution	*start;
	t_solution	**cur;
	t_shortcut	best_shortcut;

	n_imp = 1;
	while (n_imp > 0)
	{
		init(&n_imp, &start, &cur, head);
		while (start)
		{
			fill_cur(cur, N_STEPS);
			best_shortcut = find_best_shortcut(cur, start);
			if (best_shortcut.n > 7)
			{
				apply_shortcut(start, cur, best_shortcut, n_imp++);
				start = best_shortcut.end;
			}
			else
				start = lst_get_nth(start, N_STEPS);
			if (lst_len(start) <= N_STEPS)
				break ;
		}
	}
	return (head);
}

static void	init(int *n_sub, t_solution **start, t_solution ***prev,
		t_solution *head)
{
	*n_sub = 0;
	*start = head;
	*prev = malloc(sizeof(t_solution **) * 2);
	check_malloc(*prev);
	*prev[0] = head;
	*prev[1] = NULL;
}
