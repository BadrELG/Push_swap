/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:55:00 by badr              #+#    #+#             */
/*   Updated: 2025/08/07 15:44:03 by badr             ###   ########.fr       */
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

/* Convertit une chaîne en long avec détection de débordement */
long	convert_with_overflow_check(char *str, int start, int sign, int *error)
{
	long	result;

	result = 0;
	while (str[start])
	{
		result = result * 10 + (str[start] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && result * sign < INT_MIN))
		{
			*error = 1;
			return (0);
		}
		start++;
	}
	return (result * sign);
}

/* Convertit une chaîne en entier avec gestion d'erreur */
int	ft_atoi_error(char *str, int *error)
{
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	return ((int)convert_with_overflow_check(str, i, sign, error));
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
