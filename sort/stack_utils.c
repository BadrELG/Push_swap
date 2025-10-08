/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:00:00 by badr              #+#    #+#             */
/*   Updated: 2025/10/08 19:59:32 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Vérifie si la pile est déjà triée dans l'ordre croissant */
int	is_stack_sorted(t_list *stack)
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

/*
** Déplace les éléments selon la valeur du bit visé.
** Les zéros partent dans stack_b, les uns restent via une rotation.
*/
void	sort_current_bit_position(t_list **stack_a, t_list **stack_b,
	int bit_pos, int size)
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

/*
** Ramène l'élément ciblé en tête de pile via la rotation la plus courte.
** Choisit ra ou rra en fonction de la moitié dans laquelle l'élément se trouve.
*/
void	rotate_element_to_top(t_list **stack, int index)
{
	int	size;

	size = ft_lstsize(*stack);
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
