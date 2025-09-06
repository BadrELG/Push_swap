/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:00:00 by badr              #+#    #+#             */
/*   Updated: 2025/09/06 16:00:00 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Trouve l'index du minimum dans la pile */
int	find_min_index(t_list *stack)
{
	int	min_val;
	int	min_index;
	int	index;

	if (!stack)
		return (-1);
	min_val = *(int *)stack->content;
	min_index = 0;
	index = 0;
	while (stack)
	{
		if (*(int *)stack->content < min_val)
		{
			min_val = *(int *)stack->content;
			min_index = index;
		}
		stack = stack->next;
		index++;
	}
	return (min_index);
}

/* Tri optimisé pour 3 éléments - gère tous les cas possibles */
void	sort_three(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (!stack_a || !*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	a = *(int *)(*stack_a)->content;
	b = *(int *)(*stack_a)->next->content;
	c = *(int *)(*stack_a)->next->next->content;
	if (a > b && b < c && a < c)
		sa(stack_a, 1);
	else if (a > b && b > c)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a, 1);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a, 1);
}

/* Tri optimisé pour 5 éléments */
void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	min_index;
	int	size;

	size = get_list_size(*stack_a);
	if (size <= 3)
	{
		sort_three(stack_a);
		return ;
	}
	if (size == 4)
	{
		sort_four(stack_a, stack_b);
		return ;
	}
	while (get_list_size(*stack_a) > 3)
	{
		min_index = find_min_index(*stack_a);
		move_to_top(stack_a, min_index);
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

/* Fonction dispatcher principale pour les petites piles */
void	sort_small(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = get_list_size(*stack_a);
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
			sa(stack_a, 1);
	}
	else if (size <= 5)
		sort_five(stack_a, stack_b);
}
