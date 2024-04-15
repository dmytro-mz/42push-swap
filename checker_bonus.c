/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 10:33:24 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/14 11:35:44 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	do_operations(t_state *state);
static void	do_rotation(char *line, t_state *state, t_list *mock);
static void	wrong_operation_error(char *line, t_state *state, t_list *mock);

int	main(int ac, char **av)
{
	t_state	state;

	if (ac > 1)
	{
		state = parse_args(ac - 1, av + 1);
		do_operations(&state);
		if (is_sorted(state) && state.break_point == 0)
			ft_putendl_fd("OK", STDOUT_FILENO);
		else
			ft_putendl_fd("KO", STDOUT_FILENO);
		free(state.stacks);
	}
	return (0);
}

static void	do_operations(t_state *state)
{
	char	*line;
	t_list	*mock;

	mock = NULL;
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (!ft_memcmp(line, "sa\n", 4))
			swap_a(state, &mock);
		else if (!ft_memcmp(line, "sb\n", 4))
			swap_b(state, &mock);
		else if (!ft_memcmp(line, "ss\n", 4))
			swap_ab(state, &mock);
		else if (!ft_memcmp(line, "pa\n", 4))
			push_a(state, &mock);
		else if (!ft_memcmp(line, "pb\n", 4))
			push_b(state, &mock);
		else if (!ft_memcmp(line, "r", 1))
			do_rotation(line, state, mock);
		else
			wrong_operation_error(line, state, mock);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free_solution(mock);
}

static void	do_rotation(char *line, t_state *state, t_list *mock)
{
	if (!ft_memcmp(line, "ra\n", 4))
		rot_a(state, &mock);
	else if (!ft_memcmp(line, "rb\n", 4))
		rot_b(state, &mock);
	else if (!ft_memcmp(line, "rr\n", 4))
		rot_ab(state, &mock);
	else if (!ft_memcmp(line, "rra\n", 5))
		rrot_a(state, &mock);
	else if (!ft_memcmp(line, "rrb\n", 5))
		rrot_b(state, &mock);
	else if (!ft_memcmp(line, "rrr\n", 5))
		rrot_ab(state, &mock);
	else
		wrong_operation_error(line, state, mock);
}

static void	wrong_operation_error(char *line, t_state *state, t_list *mock)
{
	free(line);
	free(state->stacks);
	free_solution(mock);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(42);
}
