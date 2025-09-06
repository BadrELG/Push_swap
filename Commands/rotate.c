/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:53:00 by badr              #+#    #+#             */
/*   Updated: 2025/08/07 16:05:50 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Fait tourner la pile A : premier élément devient dernier */
void	ra(t_list **list_a, int print)
{
	t_list	*tmp;

	if (!list_a || !*list_a || !(*list_a)->next)
		return ;
	tmp = *list_a;
	*list_a = (*list_a)->next;
	tmp->next = NULL;
	ft_lstadd_back(list_a, tmp);
	if (print)
		ft_putstr_fd("ra\n", 1);
}

/* Fait tourner la pile B : premier élément devient dernier */
void	rb(t_list **list_b, int print)
{
	t_list	*tmp;

	if (!list_b || !*list_b || !(*list_b)->next)
		return ;
	tmp = *list_b;
	*list_b = (*list_b)->next;
	tmp->next = NULL;
	ft_lstadd_back(list_b, tmp);
	if (print)
		ft_putstr_fd("rb\n", 1);
}

/* Fait tourner simultanément les piles A et B */
void	rr(t_list **list_a, t_list **list_b)
{
	ra(list_a, 0);
	rb(list_b, 0);
	ft_putstr_fd("rr\n", 1);
}
