/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:55:00 by badr              #+#    #+#             */
/*   Updated: 2025/10/08 14:55:22 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Libère le tableau retourné par ft_split */
static void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

/* Récupère les arguments selon le format d'entrée */
char	**get_args(int argc, char **argv)
{
	char	**args;

	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	return (args);
}

/* Construit la pile A à partir des arguments validés */
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

/* Parse et valide tous les arguments d'entrée */
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

/* Fonction principale : parse, trie et nettoie la mémoire */
int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**args;
	int		need_free_args;

	if (argc < 2)
		return (0);
	args = get_args(argc, argv);
	need_free_args = (argc == 2);
	if (!args || (need_free_args && !args[0]))
		return (ft_putstr_fd("Error\n", 2), 1);
	stack_a = build_stack(args);
	if (!stack_a)
	{
		if (need_free_args)
			free_split(args);
		return (ft_putstr_fd("Error\n", 2), 1);
	}
	stack_b = NULL;
	if (!is_stack_sorted(stack_a))
		radix_sort(&stack_a, &stack_b);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	if (need_free_args)
		free_split(args);
	return (0);
}
