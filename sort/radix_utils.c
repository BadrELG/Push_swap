/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:00:00 by badr              #+#    #+#             */
/*   Updated: 2025/10/17 14:08:28 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	free_arrays(int *original, int *sorted, int *indexed)
{
	if (original)
		g_free(original);
	if (sorted)
		g_free(sorted);
	if (indexed)
		g_free(indexed);
}

int	*convert_stack_to_array(t_list *stack, int size)
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

int	*normalize_stack_indices(t_list *stack, int size)
{
	int	*original;
	int	*sorted;
	int	*indexed;
	int	i;

	original = convert_stack_to_array(stack, size);
	sorted = g_malloc(sizeof(int) * size);
	indexed = g_malloc(sizeof(int) * size);
	if (!original || !sorted || !indexed)
		return (free_arrays(original, sorted, indexed), NULL);
	i = -1;
	while (++i < size)
		sorted[i] = original[i];
	ft_sort_int_tab(sorted, size);
	i = 0;
	while (i < size)
	{
		indexed[i] = find_value_index_in_sorted(sorted, size, original[i]);
		i++;
	}
	g_free(original);
	g_free(sorted);
	return (indexed);
}
