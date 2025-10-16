/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:54:00 by badr              #+#    #+#             */
/*   Updated: 2025/10/16 13:56:20 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list **list_a, int print)
{
	void	*tmp;

	if (!list_a || !*list_a || !(*list_a)->next)
		return ;
	tmp = (*list_a)->content;
	(*list_a)->content = (*list_a)->next->content;
	(*list_a)->next->content = tmp;
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_list **list_b, int print)
{
	void	*tmp;

	if (!list_b || !*list_b || !(*list_b)->next)
		return ;
	tmp = (*list_b)->content;
	(*list_b)->content = (*list_b)->next->content;
	(*list_b)->next->content = tmp;
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_list **list_a, t_list **list_b)
{
	sa(list_a, 0);
	sb(list_b, 0);
	ft_putstr_fd("ss\n", 1);
}
