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

/* Algorithme de tri radix principal - version simplifiée */
void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int			size;
	int			max_bits;
	int			*indexed;
	int			bit;
	int			i;
	t_list		*current;

	current = *stack_a;
	i = 0;
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
	while (current && i < size)
	{
		*(int *)current->content = indexed[i];
		current = current->next;
		i++;
	}
	max_bits = get_max_bits(size - 1);
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
