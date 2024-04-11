/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cost_based_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:57:21 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/10 16:15:21 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_cost_based.h"

static void	set_cost_move_defaults(t_cost_move *c, t_cost_move *b,
				t_state *state);
static int	find_target_pos(t_state *state, int b_i);
static void	move(t_state *state, t_list **solution, t_cost_move *best);
static void	move_if_a_nonzero(t_state *state, t_list **solution,
				t_cost_move *best);

void	do_cost_based_move(t_state *state, t_list **solution)
{
	t_cost_move		best;
	t_cost_move		cur;
	unsigned int	i;
	int				b_i;

	set_cost_move_defaults(&cur, &best, state);
	i = 0;
	while (i < state->break_point)
	{
		cur.b_moves = i;
		b_i = state->stacks[state->break_point - 1 - i];
		cur.a_moves = find_target_pos(state, b_i);
		estimate_n_update_cost(&cur, &best);
		i++;
	}
	move(state, solution, &best);
}

static void	set_cost_move_defaults(t_cost_move *c, t_cost_move *b,
		t_state *state)
{
	b->a_moves = 0;
	b->b_moves = 0;
	b->size = state->size;
	b->breaking_point = state->break_point;
	b->best_cost = INT_MAX;
	ft_memmove(c, b, sizeof(t_cost_move));
}

static int	find_target_pos(t_state *state, int b_i)
{
	int	val;
	int	pos;
	int	min_pos;
	int	i;
	int	a_i;

	pos = -1;
	val = INT_MAX;
	min_pos = 0;
	i = 0;
	while (state->break_point + i < state->size)
	{
		a_i = state->stacks[state->break_point + i];
		if (a_i > b_i && a_i < val)
		{
			pos = i;
			val = a_i;
		}
		if (a_i < state->stacks[state->break_point + min_pos])
			min_pos = i;
		i++;
	}
	if (pos >= 0)
		return (pos);
	return (min_pos);
}

static void	move(t_state *state, t_list **solution, t_cost_move *best)
{
	while (best->a_moves != 0 || best->b_moves != 0)
	{
		if (best->a_moves != 0)
			move_if_a_nonzero(state, solution, best);
		else if (best->b_moves > 0)
		{
			rot_b(state, solution);
			best->b_moves--;
		}
		else if (best->b_moves < 0)
		{
			rrot_b(state, solution);
			best->b_moves++;
		}
	}
	push_a(state, solution);
}

static void	move_if_a_nonzero(t_state *state, t_list **solution,
		t_cost_move *best)
{
	if (best->a_moves > 0)
	{
		if (best->b_moves > 0)
		{
			rot_ab(state, solution);
			best->b_moves--;
		}
		else
			rot_a(state, solution);
		best->a_moves--;
	}
	else if (best->a_moves < 0)
	{
		if (best->b_moves < 0)
		{
			rrot_ab(state, solution);
			best->b_moves++;
		}
		else
			rrot_a(state, solution);
		best->a_moves++;
	}
}
