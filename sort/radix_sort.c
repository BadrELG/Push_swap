/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:00:00 by badr              #+#    #+#             */
/*   Updated: 2025/09/06 16:00:00 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Compare deux entiers pour qsort */
static int	compare_ints(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

/* Convertit la pile en tableau d'indices normalisés (0 à n-1) */
int	*index_array(t_list *stack, int size)
{
	int	*original;
	int	*sorted;
	int	*indexed;
	int	i;

	original = stack_to_array(stack, size);
	sorted = g_malloc(sizeof(int) * size);
	indexed = g_malloc(sizeof(int) * size);
	if (!original || !sorted || !indexed)
		return (NULL);
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
		indexed[i] = find_index(sorted, size, original[i]);
		i++;
	}
	return (indexed);
}

/* Remplace les valeurs de la pile par leurs indices normalisés */
static void	apply_indexed_values(t_list **stack_a, int *indexed, int size)
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

/* Exécute l'algorithme radix sort bit par bit */
static void	execute_radix_bits(t_list **stack_a, t_list **stack_b, int max_bits)
{
	int	bit;
	int	size;

	bit = 0;
	while (bit < max_bits)
	{
		size = get_stack_size(*stack_a);
		process_bit(stack_a, stack_b, bit, size);
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
	size = get_stack_size(*stack_a);
	if (size <= 5)
	{
		sort_small(stack_a, stack_b);
		return ;
	}
	indexed = index_array(*stack_a, size);
	if (!indexed)
		return ;
	apply_indexed_values(stack_a, indexed, size);
	max_bits = get_max_bits(size - 1);
	execute_radix_bits(stack_a, stack_b, max_bits);
}
