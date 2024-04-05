/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:31:50 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/31 20:11:58 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_solution	*push_b(t_solution *s)
{
	t_solution	*new;

	ft_memmove(s->instr, "pb", 3);
	new = malloc(sizeof(t_solution));
	check_malloc(new);
	new->next = NULL;
	new->instr[0] = 0;
	ft_memmove(&(new->state), &(s->state), sizeof(t_state));
	if (new->state.break_point < new->state.size)
		new->state.break_point++;
	s->next = new;
	return (new);
}

t_solution	*push_a(t_solution *s)
{
	t_solution	*new;

	ft_memmove(s->instr, "pa", 3);
	new = malloc(sizeof(t_solution));
	check_malloc(new);
	new->next = NULL;
	new->instr[0] = 0;
	ft_memmove(&(new->state), &(s->state), sizeof(t_state));
	if (new->state.break_point > 0)
		new->state.break_point--;
	s->next = new;
	return (new);
}
