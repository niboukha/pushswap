/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:04:13 by niboukha          #+#    #+#             */
/*   Updated: 2023/04/01 15:00:54 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	re_push_stack_b(t_list **stack_a, int	*flag, int *size)
{
	*flag = 1;
	*size = ft_lstsize(*stack_a);
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
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	if (!is_sorted(stack_a))
		exit(0);
	if (ft_lstsize(*stack_a) == 5)
	{
		sort_5_algo(stack_a, stack_b);
		exit(0);
	}
}

void	push_in_stack_b(t_longest *lis, t_list **stack_a, t_list **stack_b,
		int flag)
{
	int	size;
	int	size_tmp;

	size = ft_lstsize(*stack_a);
	size_tmp = size;
	while (size--)
	{
		if (lis->arr_lis[(*stack_a)->index])
			ra(stack_a, 1);
		else if ((size_tmp / 2) > (*stack_a)->index || flag || size_tmp <= 100)
		{
			pb(stack_a, stack_b, 1);
			if ((!flag && ft_lstsize(*stack_b) > 1
					&& (size_tmp / ((size_tmp > 100) * 2 + 2)
						> (*stack_b)->index))
				|| ((flag && ft_lstsize(*stack_b) > 1
						&& (size_tmp * 3) / 4 > (*stack_b)->index)))
				rb(stack_b, 1);
		}
		else
			ra(stack_a, 1);
		if (size == 0 && flag == 0 && size_tmp > 200)
			re_push_stack_b(stack_a, &flag, &size);
	}
}
