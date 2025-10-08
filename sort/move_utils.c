/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:00:00 by badr              #+#    #+#             */
/*   Updated: 2025/10/08 14:44:01 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
** Recherche l'index correspondant à value dans le tableau trié.
** Utilisé pour associer chaque valeur à sa position normalisée.
*/
int	find_value_index_in_sorted(int *sorted, int size, int value)
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
