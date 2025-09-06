/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:53:00 by badr              #+#    #+#             */
/*   Updated: 2025/08/07 16:05:29 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Pousse le premier élément de B vers le haut de A */
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

/* Pousse le premier élément de A vers le haut de B */
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
