/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:00:00 by badr              #+#    #+#             */
/*   Updated: 2025/10/16 13:53:54 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
