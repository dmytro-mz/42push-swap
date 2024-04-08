/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cost_based.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:48:28 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/08 21:51:19 by dmoroz           ###   ########.fr       */
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

void	move_by_median(t_state *state, t_list **solution)
{
	int	median;
	int	n_moves;

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

int	get_a_median(t_state *state)
{
	int	*copy;
	int	i;
	int	tmp;
	int	res;

	copy = malloc((state->size - state->break_point) * sizeof(int));
	if (!copy)
		return (INT_MAX);
	ft_memmove(copy, state->stacks + state->break_point, (state->size
			- state->break_point) * sizeof(int));
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
	int		min_len;
	int		max_len;
	t_list	**mock;

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
	int	a_moves;
	int	b_moves;
	int	size;
	int	breaking_point;
	int	best_cost;
}		t_cost_move;

void	do_cost_based_move(t_state *state, t_list **solution)
{
	t_cost_move	best;
	t_cost_move	cur;
	int			i;
	int			b_i;

	set_cost_move_defaults(&cur, &best, state);
	i = 0;
	while (i < state->break_point)
	{
		cur.b_moves = i;
		b_i = state->stacks[state->break_point - 1 - i];
		cur.a_moves = find_target_pos(state, b_i);
		estimate_n_update_cost(&cur, &best);
	}
	move(state, solution, &best);
}

void	set_cost_move_defaults(t_cost_move *b, t_cost_move *c, t_state *state)
{
	b->a_moves = -1;
	b->b_moves = -1;
	b->size = state->size;
	b->breaking_point = state->break_point;
	b->best_cost = INT_MAX;
	ft_memmove(c, b, sizeof(t_cost_move));
}

int	find_target_pos(t_state *state, int b_i)
{
	int	val;
	int	pos;
	int	min_pos;
	int	i;

	pos = -1;
	val = INT_MAX;
	min_pos = 0;
	i = 0;
	while (state->break_point + i < state->size)
	{
		if (state->stacks[state->break_point + i] > b_i
			&& state->stacks[state->break_point + i] < val)
		{
			pos = i;
			val = state->stacks[state->break_point + i];
		}
		if (state->stacks[state->break_point
			+ i] < state->stacks[state->break_point + min_pos])
			min_pos = i;
		i++;
	}
	if (pos >= 0)
		return (pos);
	return (min_pos);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	estimate_n_update_cost(t_cost_move *cur, t_cost_move *best)
{
	int	r_a_moves;
	int	r_b_moves;
	int	best_a;
	int	best_b;

	r_a_moves = (cur->a_moves != 0) * (cur->size - cur->breaking_point
			- cur->a_moves);
	r_b_moves = (cur->b_moves != 0) * (cur->breaking_point - cur->b_moves);
	best_a = cur->a_moves;
	best_b = cur->b_moves;
	cur->best_cost = max(cur->a_moves, cur->b_moves);
	if (max(r_a_moves, r_b_moves) < cur->best_cost)
		cur->best_cost = ugly1(&best_a, &best_b, r_a_moves, r_b_moves);
	if (r_a_moves + cur->b_moves < cur->best_cost)
		cur->best_cost = ugly2(&best_a, &best_b, -r_a_moves, cur->b_moves);
	if (cur->a_moves + r_b_moves < cur->best_cost)
		cur->best_cost = ugly2(&best_a, &best_b, cur->a_moves, -r_b_moves);
	if (cur->best_cost < best->best_cost)
	{
		best->best_cost = cur->best_cost;
		best->a_moves = best_a;
		best->b_moves = best_b;
	}
}

int	ugly1(int *a, int *b, int new_a, int new_b)
{
	*a = new_a;
	*b = new_b;
	if (new_a < 0)
		new_a = -new_a;
	if (new_b < 0)
		new_b = -new_b;
	return (max(new_a, new_b));
}

int	ugly2(int *a, int *b, int new_a, int new_b)
{
	*a = new_a;
	*b = new_b;
	if (new_a < 0)
		new_a = -new_a;
	if (new_b < 0)
		new_b = -new_b;
	return (new_a + new_b);
}

void	move(t_state *state, t_list **solution, t_cost_move *best)
{
	while (!(best->a_moves == 0 && best->b_moves == 0))
	{
		if (best->a_moves < 0 && best->b_moves < 0)
		{
			rrot_ab(state, solution);
			best->a_moves++;
			best->b_moves++;
		}
		else if (best->a_moves > 0 && best->b_moves > 0)
		{
			rot_ab(state, solution);
			best->a_moves--;
			best->b_moves--;
		}
		else if (best->a_moves > 0)
		{
			rot_a(state, solution);
			best->a_moves--;
		}
		else if (best->a_moves < 0)
		{
			rrot_a(state, solution);
			best->a_moves++;
		}
		else if (best->b_moves > 0)
		{
			rot_a(state, solution);
			best->b_moves--;
		}
		else if (best->b_moves < 0)
		{
			rrot_a(state, solution);
			best->b_moves++;
		}
	}
	push_a(state, solution);
}
