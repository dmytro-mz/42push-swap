/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 10:32:10 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/14 12:17:51 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "get_next_line_bonus.h"
# include "libft.h"

typedef struct s_state
{
	int				*stacks;
	unsigned int	size;
	unsigned int	break_point;
}					t_state;

t_state				parse_args(unsigned int size, char **args);
int					is_sorted(t_state state);
void				free_solution(t_list *solution);
void				check_malloc(void *ptr);
// operation push
void				push_a(t_state *state, t_list **solution);
void				push_b(t_state *state, t_list **solution);
// operation swap
void				swap_a(t_state *state, t_list **solution);
void				swap_b(t_state *state, t_list **solution);
void				swap_ab(t_state *state, t_list **solution);
// operation rotate
void				rot_a(t_state *state, t_list **solution);
void				rot_b(t_state *state, t_list **solution);
void				rot_ab(t_state *state, t_list **solution);
// operation reverse rotate
void				rrot_a(t_state *state, t_list **solution);
void				rrot_b(t_state *state, t_list **solution);
void				rrot_ab(t_state *state, t_list **solution);
// get_stack_edge
int					get_a_head(t_state *state);
int					get_b_head(t_state *state);
int					get_a_tail(t_state *state);
int					get_b_tail(t_state *state);
// args validation
int					validate_arg(char *s);
int					validate_uniqueness(int *array, unsigned int size);

#endif