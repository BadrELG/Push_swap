/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:00:00 by badr              #+#    #+#             */
/*   Updated: 2025/10/17 14:08:29 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	g_free(indexed);
	max_bits = calculate_required_bits(size - 1);
	perform_radix_bit_passes(stack_a, stack_b, max_bits);
}
