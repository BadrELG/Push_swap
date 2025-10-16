/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:55:00 by badr              #+#    #+#             */
/*   Updated: 2025/10/16 13:53:37 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_error(char **args, int need_free)
{
	if (need_free)
		ft_split_free(args);
	ft_putstr_fd("Error\n", 2);
	return (1);
}

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
		return (handle_error(args, 0));
	stack_a = build_stack(args);
	if (!stack_a)
		return (handle_error(args, need_free_args));
	stack_b = NULL;
	if (!is_stack_sorted(stack_a))
		radix_sort(&stack_a, &stack_b);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	if (need_free_args)
		ft_split_free(args);
	return (0);
}
