/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbriand <gbriand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:18:05 by gbriand           #+#    #+#             */
/*   Updated: 2024/12/12 16:50:52 by gbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
/*
int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**splited;
	
	a = NULL;
	b = NULL;
	splited = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		splited = split(argv[1], ' ');
		init_stack_a(&a, splited + 1);
		free_split_result(splited);
	}
	else if (argc > 2)
		init_stack_a(&a, argv + 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	return (free_stack(&a), 0);
}
*/

void	sort_mini(t_stack_node **a)
{
	if (stack_len(*a) == 2)
		sa(a, false);
	if (stack_len(*a) == 3)
		sort_three(a);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**splited;

	a = NULL;
	b = NULL;
	splited = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		splited = split(argv[1], ' ');
		init_stack_a(&a, splited + 1);
		free_split_result(splited);
	}
	else if (argc > 2)
		init_stack_a(&a, argv + 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2 || stack_len(a) == 3)
			sort_mini(&a);
		else
			sort_stacks(&a, &b);
	}
	return (free_stack(&a), 0);
}
