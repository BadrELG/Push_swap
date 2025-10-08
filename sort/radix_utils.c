/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:00:00 by badr              #+#    #+#             */
/*   Updated: 2025/10/08 20:04:17 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Libère les tableaux temporaires */
static void	free_arrays(int *original, int *sorted, int *indexed)
{
	if (original)
		free(original);
	if (sorted)
		free(sorted);
	if (indexed)
		free(indexed);
}

/*
** Convertit la pile en tableau d'entiers pour faciliter les traitements.
** Utile pour normaliser les valeurs avant d'appliquer le radix sort.
*/
int	*convert_stack_to_array(t_list *stack, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
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

/*
** Retourne le nombre de bits nécessaires pour représenter max_val.
** Permet de connaître le nombre de passes à effectuer en radix sort.
*/
int	calculate_required_bits(int max_val)
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
** Crée un tableau d'indices normalisés (0..n-1) basé sur l'ordre trié.
** Permet d'appliquer un radix sort sur des valeurs compactes.
*/
int	*normalize_stack_indices(t_list *stack, int size)
{
	int	*original;
	int	*sorted;
	int	*indexed;
	int	i;

	original = convert_stack_to_array(stack, size);
	sorted = malloc(sizeof(int) * size);
	indexed = malloc(sizeof(int) * size);
	if (!original || !sorted || !indexed)
		return (free_arrays(original, sorted, indexed), NULL);
	i = 0;
	while (i < size)
	{
		sorted[i] = original[i];
		i++;
	}
	ft_sort_int_tab(sorted, size);
	i = 0;
	while (i < size)
	{
		indexed[i] = find_value_index_in_sorted(sorted, size, original[i++]);
	}
	free(original);
	free(sorted);
	return (indexed);
}
