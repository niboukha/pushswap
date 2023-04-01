/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:40:56 by niboukha          #+#    #+#             */
/*   Updated: 2023/04/01 14:52:48 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_atoi(char *str)
{
	int			i;
	long		result;
	int			sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] && str[i] <= 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - 48;
	if ((result * sign) > INT_MAX
		|| (result * sign) < INT_MIN)
	{
		write(2, "Error\n", 7);
		exit(1);
	}
	return (result * sign);
}

int	handel_numbers(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '+' || str[i][j] == '-')
				j++;
			if (str[i][j] < '0' || str[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_double(t_list *stack_a)
{
	t_list	*tmp;

	while (stack_a->next)
	{
		tmp = stack_a->next;
		while (tmp)
		{
			if (stack_a->data == tmp->data)
				return (1);
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}

int	is_sorted(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (!(*stack_a))
		return (0);
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
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
