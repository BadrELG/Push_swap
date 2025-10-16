/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:55:00 by badr              #+#    #+#             */
/*   Updated: 2025/10/16 13:55:01 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**get_args(int argc, char **argv)
{
	char	**args;

	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	return (args);
}

t_list	*parse_args(int argc, char **argv)
{
	char	**args;
	t_list	*stack_a;

	args = get_args(argc, argv);
	if (!args)
		return (NULL);
	stack_a = build_stack(args);
	return (stack_a);
}

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

t_list	*build_stack(char **args)
{
	t_list	*stack_a;
	int		*num;
	int		error;
	int		i;

	stack_a = NULL;
	i = 0;
	while (args[i])
	{
		error = 0;
		if (!valid_nbr(args[i]))
			return (ft_lstclear(&stack_a, free), NULL);
		num = malloc(sizeof(int));
		if (!num)
			return (ft_lstclear(&stack_a, free), NULL);
		*num = ft_atoi_safe(args[i], &error);
		if (error)
			return (free(num), ft_lstclear(&stack_a, free), NULL);
		ft_lstadd_back(&stack_a, ft_lstnew(num));
		i++;
	}
	if (check_doubles(stack_a))
		return (ft_lstclear(&stack_a, free), NULL);
	return (stack_a);
}
