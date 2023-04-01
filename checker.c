/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:39:34 by niboukha          #+#    #+#             */
/*   Updated: 2023/04/01 15:14:26 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "get_next_line.h"

void	handle_error(void)
{
	write(2, "Error\n", 7);
	exit(1);
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
			if (ft_strlen(av[j + 1]) == 0)
				handle_error();
			split_args = ft_split(av[j + 1], ' ');
			if (!split_args[0])
				handle_error();
			while (split_args[++i])
				handel_args(split_args, &stack_a, i);
		}
		ft_checker(&stack_a, &stack_b);
	}
	return (0);
}

void	instr(t_list **stack_a, t_list **stack_b, char *get_line)
{
	if (!ft_strcmp(get_line, "sa\n"))
		ch_sa(stack_a);
	else if (!ft_strcmp(get_line, "sb\n"))
		ch_sb(stack_b);
	else if (!ft_strcmp(get_line, "ss\n"))
		ch_ss(stack_a, stack_b);
	else if (!ft_strcmp(get_line, "pa\n"))
		ch_pa(stack_a, stack_b);
	else if (!ft_strcmp(get_line, "pb\n"))
		ch_pb(stack_a, stack_b);
	else if (!ft_strcmp(get_line, "ra\n"))
		ch_ra(stack_a);
	else if (!ft_strcmp(get_line, "rb\n"))
		ch_rb(stack_b);
	else if (!ft_strcmp(get_line, "rr\n"))
		ch_rr(stack_a, stack_b);
	else if (!ft_strcmp(get_line, "rra\n"))
		ch_rra(stack_a);
	else if (!ft_strcmp(get_line, "rrb\n"))
		ch_rrb(stack_b);
	else if (!ft_strcmp(get_line, "rrr\n"))
		ch_rrr(stack_a, stack_b);
	else
		handle_error();
}

void	ft_checker(t_list **stack_a, t_list **stack_b)
{
	char	*get_line;

	get_line = get_next_line(0);
	while (get_line)
	{
		instr(stack_a, stack_b, get_line);
		get_line = get_next_line(0);
	}
	if (is_sorted(stack_a) && !ft_lstsize(*stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
