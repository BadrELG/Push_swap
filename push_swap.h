/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:52:00 by badr              #+#    #+#             */
/*   Updated: 2025/10/08 14:55:22 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

/* Commands */
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	sa(t_list **stack_a, int print);
void	sb(t_list **stack_b, int print);
void	ss(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a, int print);
void	rb(t_list **stack_b, int print);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a, int print);
void	rrb(t_list **stack_b, int print);
void	rrr(t_list **stack_a, t_list **stack_b);

/* Parsing */
int		check_doubles(t_list *stack);
int		valid_nbr(char *str);
char	**get_args(int argc, char **argv);
t_list	*build_stack(char **args);
t_list	*parse_args(int argc, char **argv);

/* Sort */

/* Fonctions principales de tri (radix_sort.c) */
void	radix_sort(t_list **stack_a, t_list **stack_b);
int		*normalize_stack_indices(t_list *stack, int size);

/* Fonctions utilitaires (sort_utils.c) */
int	calculate_required_bits(int max_val);
int		is_stack_sorted(t_list *stack);
int		*convert_stack_to_array(t_list *stack, int size);
void	sort_current_bit_position(t_list **stack_a, t_list **stack_b,
		int bit_pos, int size);

/* Fonctions pour petites piles (small_sort.c) */
void	sort_three(t_list **stack_a);
void	sort_five(t_list **stack_a, t_list **stack_b);
void	sort_small(t_list **stack_a, t_list **stack_b);
void	sort_four(t_list **stack_a, t_list **stack_b);
int		find_min_index(t_list *stack);

/* Fonctions de mouvement (move_utils.c) */
void	rotate_element_to_top(t_list **stack, int index);
int		find_value_index_in_sorted(int *sorted, int size, int value);

#endif
