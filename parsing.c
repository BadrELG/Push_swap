/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:55:00 by badr              #+#    #+#             */
/*   Updated: 2025/10/08 14:55:22 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Vérifie si une chaîne représente un nombre valide */
int	valid_nbr(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/* Vérifie s'il y a des doublons dans la pile */
int	check_doubles(t_list *stack)
{
	t_list	*current;
	t_list	*check;
	int		curr_val;
	int		check_val;

	current = stack;
	while (current)
	{
		curr_val = *(int *)(current->content);
		check = current->next;
		while (check)
		{
			check_val = *(int *)(check->content);
			if (curr_val == check_val)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}
