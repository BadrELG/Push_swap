/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:55:00 by badr              #+#    #+#             */
/*   Updated: 2025/08/07 15:44:22 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			return (NULL);
		num = g_malloc(sizeof(int));
		if (!num)
			return (NULL);
		*num = ft_atoi_error(args[i], &error);
		if (error)
			return (NULL);
		ft_lstadd_back(&stack_a, ft_lstnew(num));
		i++;
	}
	if (check_doubles(stack_a))
		return (NULL);
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

	if (argc < 2)
	{
		garbage_destroy();
		return (0);
	}
	stack_a = parse_args(argc, argv);
	if (!stack_a)
	{
		ft_putstr_fd("Error\n", 2);
		garbage_destroy();
		return (1);
	}
	stack_b = NULL;
	if (!is_sorted(stack_a))
		radix_sort(&stack_a, &stack_b);
	garbage_destroy();
	return (0);
}
