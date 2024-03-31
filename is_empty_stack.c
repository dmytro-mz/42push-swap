/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:31:50 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/31 19:32:09 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_a_empty(t_solution *s)
{
	return (s->state.break_point == s->state.size);
}

int	is_b_empty(t_solution *s)
{
	return (s->state.break_point == 0);
}
