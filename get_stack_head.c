/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack_head.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:31:50 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/31 19:54:01 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_a_head(t_solution *s)
{
	return (s->state.stacks[s->state.break_point]);
}

int	get_b_head(t_solution *s)
{
	return (s->state.stacks[s->state.break_point - 1]);
}
