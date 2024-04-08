/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cost_based.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:48:28 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/06 15:49:52 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*cost_based_sort(t_state state)
{
	t_list	*solution;

	solution = NULL;
	move_by_median(&state, &solution);
	ft_lstadd_back(&solution, get_best_bubble_solution(&state));
	while (!is_b_empty(state))
		do_cost_based_move(&state, &solution);
	move_a_to_n(&state, get_smallest_a(state), &solution);
	return (solution);
}

void move_by_median(t_state *state, t_list **solution)
{
	int median;
	int n_moves;

	median = get_a_median(state);
	n_moves = 0;
	while (get_a_size(state) > 3)
	{
		if (get_a_head(state) <= median || n_moves > state->size / 2)
		{
			push_b(state, solution);
			n_moves++;
		}
		else
			rot_a(state, solution);
	}
}

int get_a_median(t_state *state)
{
	int *copy;
	int i;
	int tmp;
	int res;

	copy = malloc((state->size - state->break_point) * sizeof(int));
	if (!copy)
		return (INT_MAX);
	ft_memmove(copy, state->stacks + state->break_point, (state->size - state->break_point) * sizeof(int));
	i = 0;
	while (i < state->size - 1)
	{
		if (copy[i] > copy[i + 1])
		{
			tmp = copy[i];
			copy[i] = copy[i + 1];
			copy[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	res = copy[(state->size - state->break_point) / 2];
	free(copy);
	return (res);
}

t_list	*get_best_bubble_solution(t_state *state)
{
	int	min_len;
	int	max_len;
	t_list **mock;

	min_len = INT_MAX;
	max_len = INT_MAX;
	try_strategy(*state, &bubble_sort_min, mock, &min_len);
	try_strategy(*state, &bubble_sort_max, mock, &max_len);
	if (min_len <= max_len)
		return (bubble_sort_min(*state));
	return (bubble_sort_max(*state));
}

typedef struct s_cost_move
{
	int a_moves;
	int b_moves;
	int size;
	int breaking_point;
	int best_cost;
} t_cost_move;

void do_cost_based_move(t_state *state, t_list **solution)
{
	t_cost_move best;
	t_cost_move cur;
	int i;

	set_cost_move_defaults(&cur, &best, state);
	i = 0;
	while (i < state->break_point)
	{
		cur.b_moves = i;
		cur.a_moves = find_target_pos(state, state->stacks[state->break_point - 1 - i]);
		estimate_n_update_cost(&cur, &best);
	}
	move(state, solution, best);
}
