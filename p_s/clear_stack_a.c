/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_stack_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:13:28 by niboukha          #+#    #+#             */
/*   Updated: 2023/04/27 12:22:58 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

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

void	clear_stack_a(t_list **stack_a)
{
	t_list	*tmp;
	int		i;
	int		size;

	size = ft_lstsize(*stack_a);
	i = 0;
	tmp = *stack_a;
	while (tmp)
	{
		if (!tmp->index)
		{
			if (i < size / 2)
				ra(stack_a, i);
			else
				rra(stack_a, size - i);
		}
		i++;
		tmp = tmp->next;
	}
}
