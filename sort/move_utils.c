/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:00:00 by badr              #+#    #+#             */
/*   Updated: 2025/09/06 16:00:00 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Trouve l'index d'une valeur dans un tableau trié */
int	find_index(int *sorted, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

/* Calcule la taille de la pile (version alternative) */
int	get_list_size(t_list *stack)
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

/* Déplace un élément à l'index donné vers le top de manière optimale */
void	move_to_top(t_list **stack, int index)
{
	int	size;

	size = get_list_size(*stack);
	if (index <= size / 2)
	{
		while (index > 0)
		{
			ra(stack, 1);
			index--;
		}
	}
	else
	{
		index = size - index;
		while (index > 0)
		{
			rra(stack, 1);
			index--;
		}
	}
}

/* Tri optimisé pour 4 éléments */
void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	min_index;

	min_index = find_min_index(*stack_a);
	move_to_top(stack_a, min_index);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}
