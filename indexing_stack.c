/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:05:14 by niboukha          #+#    #+#             */
/*   Updated: 2023/03/31 00:34:05 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	largest_element(t_list *stack_a)
{
	t_list	*tmp;
	int		max;

	tmp = stack_a;
	while (tmp)
	{
		if (tmp->index == -1)
		{
			max = tmp->data;
			break ;
		}
		tmp = tmp->next;
	}
	while (stack_a)
	{
		if (max < stack_a->data && stack_a->index == -1)
			max = stack_a->data;
		stack_a = stack_a->next;
	}
	return (max);
}

void	indexing_stack(t_list *stack_a)
{
	t_list	*tmp;
	int		length;
	int		max;

	length = ft_lstsize(stack_a);
	while (length > 0)
	{
		tmp = stack_a;
		max = largest_element(tmp);
		while (tmp)
		{
			if (tmp->data == max)
				tmp->index = --length;
			tmp = tmp->next;
		}
	}
	length = ft_lstsize(stack_a);
	while (length-- > 0)
	{
		stack_a->data = stack_a->index;
		stack_a = stack_a->next;
	}
}

int	get_max(t_list *stack_a)
{
	int	max;

	max = 0;
	while (stack_a)
	{
		if (max < stack_a->index)
			max = stack_a->index;
		stack_a = stack_a->next;
	}
	return (max);
}

int	_max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

int	_min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}
