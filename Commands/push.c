/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:53:00 by badr              #+#    #+#             */
/*   Updated: 2025/10/16 13:55:52 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_list **list_a, t_list	**list_b)
{
	t_list	*list_tmp;

	if (!*list_b)
		return ;
	list_tmp = *list_b;
	*list_b = (*list_b)->next;
	ft_lstadd_front(list_a, list_tmp);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list **list_a, t_list **list_b)
{
	t_list	*list_tmp;

	if (!*list_a)
		return ;
	list_tmp = *list_a;
	*list_a = (*list_a)->next;
	ft_lstadd_front(list_b, list_tmp);
	ft_putstr_fd("pb\n", 1);
}
