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

/* Compare deux entiers pour qsort */
int	compare_ints(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
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
