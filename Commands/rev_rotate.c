/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:54:00 by badr              #+#    #+#             */
/*   Updated: 2025/08/07 16:05:24 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Rotation inverse pile A : dernier élément devient premier */
void	rra(t_list **list_a, int print)
{
	t_list	*before_last;
	t_list	*last;
	t_list	*tmp;

	if (!list_a || !*list_a || !(*list_a)->next)
		return ;
	tmp = *list_a;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	before_last = tmp;
	last = tmp->next;
	before_last->next = NULL;
	last->next = *list_a;
	*list_a = last;
	if (print)
		ft_putstr_fd("rra\n", 1);
}

/* Rotation inverse pile B : dernier élément devient premier */
void	rrb(t_list **list_b, int print)
{
	t_list	*before_last;
	t_list	*last;
	t_list	*tmp;

	if (!list_b || !*list_b || !(*list_b)->next)
		return ;
	tmp = *list_b;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	before_last = tmp;
	last = tmp->next;
	before_last->next = NULL;
	last->next = *list_b;
	*list_b = last;
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

/* Rotation inverse simultanée des piles A et B */
void	rrr(t_list **list_a, t_list **list_b)
{
	rra(list_a, 0);
	rrb(list_b, 0);
	ft_putstr_fd("rrr\n", 1);
}
