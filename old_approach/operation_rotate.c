/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:31:50 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/31 20:11:42 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_solution	*get_new(t_solution *s);

t_solution	*rotate_a(t_solution *s)
{
	t_solution	*new;
	int			top;
	t_state		t;

	ft_memmove(s->instr, "ra", 3);
	new = get_new(s);
	if (new->state.size - new->state.break_point >= 2)
	{
		top = get_a_head(new);
		t = new->state;
		ft_memmove(t.stacks + t.break_point, t.stacks + t.break_point + 1,
			t.size - t.break_point - 1);
		t.stacks[t.size - 1] = top;
	}
	s->next = new;
	return (new);
}

t_solution	*rotate_b(t_solution *s)
{
	t_solution	*new;
	int			top;
	t_state		t;

	ft_memmove(s->instr, "rb", 3);
	new = get_new(s);
	if (new->state.break_point >= 2)
	{
		top = get_b_head(new);
		t = new->state;
		ft_memmove(t.stacks + 1, t.stacks, t.break_point - 1);
		t.stacks[t.break_point - 1] = top;
	}
	s->next = new;
	return (new);
}

t_solution	*rotate_ab(t_solution *s)
{
	t_solution	*new;
	int			top;
	t_state		t;

	ft_memmove(s->instr, "rr", 3);
	new = get_new(s);
	if (new->state.size - new->state.break_point >= 2)
	{
		top = get_a_head(new);
		t = new->state;
		ft_memmove(t.stacks + t.break_point, t.stacks + t.break_point + 1,
			t.size - t.break_point - 1);
		t.stacks[t.size - 1] = top;
	}
	if (new->state.break_point >= 2)
	{
		top = get_b_head(new);
		t = new->state;
		ft_memmove(t.stacks + 1, t.stacks, t.break_point - 1);
		t.stacks[t.break_point - 1] = top;
	}
	s->next = new;
	return (new);
}

static t_solution	*get_new(t_solution *s)
{
	t_solution	*new;

	new = malloc(sizeof(t_solution));
	check_malloc(new);
	new->next = NULL;
	new->instr[0] = 0;
	ft_memmove(&(new->state), &(s->state), sizeof(t_state));
}
