/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:45:08 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/15 11:19:25 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

typedef struct s_state
{
	int				*stacks;
	unsigned int	size;
	unsigned int	break_point;
}					t_state;

t_list				*bubble_sort_min(t_state state);
t_list				*bubble_sort_max(t_state state);
t_list				*ez_sort(t_state state);
t_list				*ez_pz_sort(t_state state);
t_list				*cost_based_sort(t_state state);
t_state				parse_args(unsigned int size, char **args);
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
// is_empty
int					is_a_empty(t_state state);
int					is_b_empty(t_state state);
// args validation
int					validate_arg(char *s);
int					validate_uniqueness(int *array, unsigned int size);
// other
void				move_a_to_n(t_state *state, int n, t_list **solution);
int					estimate_move_a_to_n(t_state *state, int n);
int					is_sorted(t_state state);
int					get_smallest_a(t_state state);
int					get_largest_a(t_state state);
int					get_a_size(t_state *state);
void				repeat(void (*f)(t_state *, t_list **), int n,
						t_state *state, t_list **solution);
void				check_malloc(void *ptr);
void				try_strategy(t_state stack, t_list *(*f)(t_state),
						t_list **best_stack, int *best_stack_len);
void				move_a_to_closest_swap(t_state *state, int n,
						t_list **solution);
void				free_solution(t_list *solution);
t_list				*get_best_bubble_solution(t_state *state);

#endif