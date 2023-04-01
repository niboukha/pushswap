/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundling_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:03:24 by niboukha          #+#    #+#             */
/*   Updated: 2023/04/01 14:50:48 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a)
{
	t_list	*new;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	write(1, "sa\n", 3);
	new = (*stack_a)->next;
	(*stack_a)->next = (*stack_a)->next->next;
	ft_lstadd_front(stack_a, new);
}

void	sb(t_list **stack_b)
{
	t_list	*new;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	write(1, "sb\n", 3);
	new = (*stack_b)->next;
	(*stack_b)->next = (*stack_b)->next->next;
	ft_lstadd_front(stack_b, new);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	t_list	*new_a;
	t_list	*new_b;

	if (!(*stack_a) || !(*stack_a)->next
		|| !(*stack_b) || !(*stack_b)->next)
		return ;
	write(1, "ss\n", 3);
	new_a = (*stack_a)->next;
	new_b = (*stack_b)->next;
	(*stack_a)->next = (*stack_a)->next->next;
	(*stack_b)->next = (*stack_b)->next->next;
	ft_lstadd_front(stack_a, new_a);
	ft_lstadd_front(stack_b, new_b);
}

void	pa(t_list **stack_a, t_list **stack_b, int n)
{
	t_list	*new;

	if (!(*stack_b) || n == 0)
		return ;
	write(1, "pa\n", 3);
	new = *stack_b;
	*stack_b = (*stack_b)->next;
	new->next = NULL;
	ft_lstadd_front(stack_a, new);
	if (n > 0)
		pa(stack_a, stack_b, n - 1);
}

void	pb(t_list **stack_a, t_list **stack_b, int n)
{
	t_list	*new;

	if (!(*stack_a) || n == 0)
		return ;
	write(1, "pb\n", 3);
	new = *stack_a;
	*stack_a = (*stack_a)->next;
	new->next = NULL;
	ft_lstadd_front(stack_b, new);
	if (n > 0)
		pb(stack_a, stack_b, n - 1);
}
