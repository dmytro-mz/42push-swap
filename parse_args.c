/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:06:03 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/11 13:28:38 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_single_arg(unsigned int *size, char ***args);
static void	free_split(char **args);
static void	do_on_error(void *stacks, int is_free_args, void *args);

t_state	parse_args(unsigned int size, char **args)
{
	unsigned int	i;
	int				is_single_arg;
	t_state			state;

	is_single_arg = 0;
	if (size == 1)
		split_single_arg(&size + is_single_arg++, &args);
	state.stacks = malloc(sizeof(int) * size);
	if (!state.stacks)
		do_on_error(state.stacks, is_single_arg, args);
	i = 0;
	while (i < size)
	{
		if (!validate_arg(args[i]))
			do_on_error(state.stacks, is_single_arg, args);
		state.stacks[i] = ft_atoi(args[i]);
		i++;
	}
	if (!validate_uniqueness(state.stacks, size))
		do_on_error(state.stacks, is_single_arg, args);
	state.size = size;
	state.break_point = 0;
	if (is_single_arg)
		free_split(args);
	return (state);
}

static void	split_single_arg(unsigned int *size, char ***args)
{
	int	i;

	*args = ft_split((*args)[0], ' ');
	check_malloc(*args);
	i = 0;
	while ((*args)[i])
	{
		i++;
	}
	*size = i;
	if (i == 0)
		do_on_error(*args, 0, 0);
}

static void	free_split(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

static void	do_on_error(void *stacks, int is_free_args, void *args)
{
	free(stacks);
	if (is_free_args)
		free_split(args);
	ft_putendl_fd("Error", 2);
	exit(42);
}
