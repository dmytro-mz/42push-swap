/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:31:50 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/03 17:36:19 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_a_empty(t_state state)
{
	return (state.break_point == state.size);
}

int	is_b_empty(t_state state)
{
	return (state.break_point == 0);
}
