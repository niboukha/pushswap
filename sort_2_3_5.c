/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_3_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:20:00 by niboukha          #+#    #+#             */
/*   Updated: 2023/04/01 03:07:17 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_algo(t_list **stack_a)
{
	if (!(*stack_a) && !(*stack_a)->next)
		return ;
	if (ft_lstsize(*stack_a) == 2
		&& (*stack_a)->index < (*stack_a)->next->index)
		exit(0);
	if ((*stack_a)->index > (*stack_a)->next->index)
	{
		sa(stack_a);
		exit(0);
	}
}

void	sort_3_algo(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->index;
	b = (*stack_a)->next->index;
	c = (*stack_a)->next->next->index;
	if (a > b && a < c)
		sa(stack_a);
	if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a, 1);
	}
	if (a < b && b > c && a > c)
		rra(stack_a, 1);
	if (a > b && a > c && b > c)
	{
		sa(stack_a);
		rra(stack_a, 1);
	}
	if (a > b && a > c && b < c)
		ra(stack_a, 1);
}

int	get_min(t_list *stack_a)
{
	int	min;

	min = INT_MIN;
	while (stack_a)
	{
		if (min > stack_a->index)
			min = stack_a->index;
		stack_a = stack_a->next;
	}
	return (min);
}

void	sort_5_algo(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		size;

	size = ft_lstsize(*stack_a);
	tmp = *stack_a;
	while (size--)
	{
		if (tmp->index == 0 || tmp->index == 1)
			pb(stack_a, stack_b, 1);
		else
			ra(stack_a, 1);
		tmp = *stack_a;
	}
	sort_3_algo(stack_a);
	if ((*stack_b)->data > (*stack_b)->next->data)
		pa(stack_a, stack_a, 2);
	else
	{
		sb(stack_b);
		pa(stack_a, stack_a, 2);
	}
}
