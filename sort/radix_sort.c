/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:00:00 by badr              #+#    #+#             */
/*   Updated: 2025/10/08 14:44:01 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Compare deux entiers pour qsort */
static int	compare_ints(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

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
	qsort(sorted, size, sizeof(int), compare_ints);
	i = 0;
	while (i < size)
	{
		indexed[i] = find_value_index_in_sorted(sorted, size, original[i]);
		i++;
	}
	free(original);
	free(sorted);
	return (indexed);
}

/*
** Remplace les valeurs originales de la pile par les indices normalisés.
** Chaque valeur prend sa position triée : simplifie la comparaison bit à bit.
*/
static void	apply_normalized_indices(t_list **stack_a, int *indexed, int size)
{
	t_list	*current;
	int		i;

	current = *stack_a;
	i = 0;
	while (current && i < size)
	{
		*(int *)current->content = indexed[i];
		current = current->next;
		i++;
	}
}

/*
** Parcourt chaque bit significatif et place les valeurs en conséquence.
** Après chaque passe, on rapatrie tout de stack_b vers stack_a.
*/
static void	perform_radix_bit_passes(t_list **stack_a, t_list **stack_b,
	int max_bits)
{
	int	bit;
	int	size;

	bit = 0;
	while (bit < max_bits)
	{
		size = ft_lstsize(*stack_a);
		sort_current_bit_position(stack_a, stack_b, bit, size);
		while (*stack_b)
			pa(stack_a, stack_b);
		bit++;
	}
}

/* Algorithme de tri radix principal */
void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	max_bits;
	int	*indexed;

	if (!stack_a || !*stack_a)
		return ;
	size = ft_lstsize(*stack_a);
	if (size <= 5)
	{
		sort_small(stack_a, stack_b);
		return ;
	}
	indexed = normalize_stack_indices(*stack_a, size);
	if (!indexed)
		return ;
	apply_normalized_indices(stack_a, indexed, size);
	free(indexed);
	max_bits = calculate_required_bits(size - 1);
	perform_radix_bit_passes(stack_a, stack_b, max_bits);
}
