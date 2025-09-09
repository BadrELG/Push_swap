/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:00:00 by badr              #+#    #+#             */
/*   Updated: 2025/09/06 16:00:00 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Convertit la pile en tableau d'entiers */
int	*stack_to_array(t_list *stack, int size)
{
	int	*arr;
	int	i;

	arr = g_malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (stack && i < size)
	{
		arr[i] = *(int *)stack->content;
		stack = stack->next;
		i++;
	}
	return (arr);
}

/* Retourne la taille de la pile */
int	get_stack_size(t_list *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

/* Calcule le nombre de bits nécessaires pour représenter max_val */
int	get_max_bits(int max_val)
{
	int	bits;

	bits = 0;
	while (max_val > 0)
	{
		bits++;
		max_val >>= 1;
	}
	return (bits);
}

/* Vérifie si la pile est triée dans l'ordre croissant */
int	is_sorted(t_list *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* Traite un bit spécifique du radix sort */
void	process_bit(t_list **stack_a, t_list **stack_b, int bit_pos, int size)
{
	int	i;
	int	value;

	i = 0;
	while (i < size)
	{
		value = *(int *)(*stack_a)->content;
		if (((value >> bit_pos) & 1) == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a, 1);
		i++;
	}
}
