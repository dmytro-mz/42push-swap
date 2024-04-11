/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:19:13 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/10 17:27:00 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_nothing(void *ptr);

void	free_solution(t_list *solution)
{
	ft_lstclear(&solution, &do_nothing);
}

static void	do_nothing(void *ptr)
{
	ptr++;
}
