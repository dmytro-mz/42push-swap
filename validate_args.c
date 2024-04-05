/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:06:03 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/05 13:19:10 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_arg(char *s)
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

int	validate_uniqueness(int *array, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
			if (array[i] == array[j++])
				return (0);
		i++;
	}
	return (1);
}
