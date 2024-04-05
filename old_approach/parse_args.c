/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:06:03 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/05 20:33:12 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	validate_arg(char *s);
static void	do_on_error(void *a, void *b);

int	*parse_args(int size, char **args)
{
	int		i;
	t_state	*head;

	head = malloc(sizeof(t_state));
	check_malloc(head);
	head->stacks = malloc(sizeof(int) * size);
	check_malloc(head->stacks);
	i = 0;
	while (i < size)
	{
		if (!validate_arg(args[i]))
			do_on_error(head->stacks, head);
		head->stacks[i] = ft_atoi(args[i]);
	}
	if (!validate_uniqueness(head->stacks, size))
		do_on_error(head->stacks, head);
	head->size = size;
	head->stacks = 0;
	return (head);
}

static int	validate_arg(char *s)
{
	int	len;
	int	is_negative;

	is_negative = 0;
	if (*s == '-')
	{
		s++;
		is_negative = 1;
	}
	len = ft_strlen(s);
	if (len < 1 || len > 10)
		return (0);
	else if (len == 10 && is_negative)
	{
		if (ft_strncmp(s, "2147483648", 10) > 0)
			return (0);
	}
	else if (len == 10)
		if (ft_strncmp(s, "2147483647", 10) > 0)
			return (0);
	while (*s)
		if (!ft_isdigit(*(s++)))
			return (0);
	return (1);
}

int	validate_uniqueness(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static void	do_on_error(void *a, void *b)
{
	free(a);
	free(b);
	ft_putendl_fd("Error", 2);
	exit(42);
}
