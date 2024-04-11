/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   estimate_n_update_cost.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:00:40 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/10 16:02:11 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_cost_based.h"

static int	max(int a, int b);
static int	update_bests(int bests[2], int new_a, int new_b, int is_max);

void	estimate_n_update_cost(t_cost_move *cur, t_cost_move *best)
{
	int	r_a_moves;
	int	r_b_moves;
	int	bests[2];

	r_a_moves = (cur->a_moves != 0) * (cur->size - cur->breaking_point
			- cur->a_moves);
	r_b_moves = (cur->b_moves != 0) * (cur->breaking_point - cur->b_moves);
	cur->best_cost = update_bests(bests, cur->a_moves, cur->b_moves, 1);
	if (max(r_a_moves, r_b_moves) < cur->best_cost)
		cur->best_cost = update_bests(bests, -r_a_moves, -r_b_moves, 1);
	if (r_a_moves + cur->b_moves < cur->best_cost)
		cur->best_cost = update_bests(bests, -r_a_moves, cur->b_moves, 0);
	if (cur->a_moves + r_b_moves < cur->best_cost)
		cur->best_cost = update_bests(bests, cur->a_moves, -r_b_moves, 0);
	if (cur->best_cost < best->best_cost)
	{
		best->best_cost = cur->best_cost;
		best->a_moves = bests[0];
		best->b_moves = bests[1];
	}
}

static int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static int	update_bests(int bests[2], int new_a, int new_b, int is_max)
{
	bests[0] = new_a;
	bests[1] = new_b;
	if (new_a < 0)
		new_a = -new_a;
	if (new_b < 0)
		new_b = -new_b;
	if (is_max)
		return (max(new_a, new_b));
	return (new_a + new_b);
}
