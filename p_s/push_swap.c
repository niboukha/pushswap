/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:24:30 by niboukha          #+#    #+#             */
/*   Updated: 2023/04/27 12:23:22 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
void	appel_functions(t_list **stack_a, t_list **stack_b)
{
	indexing_stack(*stack_a);
	if (ft_lstsize(*stack_a) == 2)
		sort_2_algo(stack_a);
	if (ft_lstsize(*stack_a) == 3)
	{
		sort_3_algo(stack_a);
		exit(0);
	}
	sort_5(stack_a, stack_b);
	longest_increasing_subsequence(stack_a, stack_b);
	while (*stack_b)
		rr_rrr_stack_b(stack_a, stack_b);
	clear_stack_a(stack_a);
}

void	handel_args(char **split_args, t_list **stack_a, int i)
{
	if (handel_numbers(split_args))
	{
		write(2, "Error\n", 7);
		exit(1);
	}
	ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(split_args[i])));
	if (check_double(*stack_a))
	{
		write(2, "Error\n", 7);
		exit(1);
	}
}

int	handle_error(void)
{
	write(2, "Error\n", 7);
	exit(1);
	return (1);
}

void	ft_free(char **split_args)
{
	int	i;

	i = -1;
	while (split_args[++i])
		free(split_args[i]);
	free(split_args);
}

int	main(int ac, char **av)
{
	int			i;
	int			j;
	char		**split_args;
	t_list		*stack_a;
	t_list		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac != 1)
	{
		j = -1;
		while (++j < ac - 1)
		{
			i = -1;
			(ft_strlen(av[j + 1]) == 0) && handle_error();
			split_args = ft_split(av[j + 1], ' ');
			(!split_args) && handle_error();
			while (split_args[++i])
				handel_args(split_args, &stack_a, i);
			ft_free(split_args);
		}
		appel_functions(&stack_a, &stack_b);
	}
	return (0);
}
