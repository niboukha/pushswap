/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_functions_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:00:29 by niboukha          #+#    #+#             */
/*   Updated: 2023/03/31 15:06:34 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a, int n)
{
	t_list	*first_node;

	if (!(*stack_a) || n == 0)
		return ;
	write(1, "ra\n", 3);
	first_node = *stack_a;
	*stack_a = (*stack_a)->next;
	first_node->next = NULL;
	ft_lstadd_back(stack_a, first_node);
	if (n > 0)
		ra(stack_a, n - 1);
}

void	rb(t_list **stack_b, int n)
{
	t_list	*first_node;

	if (!(*stack_b) || n == 0)
		return ;
	write(1, "rb\n", 3);
	first_node = *stack_b;
	*stack_b = (*stack_b)->next;
	first_node->next = NULL;
	ft_lstadd_back(stack_b, first_node);
	if (n > 0)
		rb(stack_b, n - 1);
}

void	rr(t_list **stack_a, t_list **stack_b, int n)
{
	t_list	*first_node_a;
	t_list	*first_node_b;

	if (!(*stack_a) || !(*stack_b) || n == 0)
		return ;
	write(1, "rr\n", 3);
	first_node_a = *stack_a;
	first_node_b = *stack_b;
	*stack_a = (*stack_a)->next;
	*stack_b = (*stack_b)->next;
	first_node_a->next = NULL;
	first_node_b->next = NULL;
	ft_lstadd_back(stack_a, first_node_a);
	ft_lstadd_back(stack_b, first_node_b);
	if (n > 0)
		rr(stack_a, stack_b, n - 1);
}

void	rra(t_list **stack_a, int n)
{
	t_list	*last_node;
	t_list	*tmp;

	tmp = *stack_a;
	if (!(*stack_a) || !(*stack_a)->next || n == 0)
		return ;
	write(1, "rra\n", 4);
	while (tmp->next->next)
		tmp = tmp->next;
	last_node = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_a, last_node);
	if (n > 0)
		rra(stack_a, n - 1);
}

void	rrb(t_list **stack_b, int n)
{
	t_list	*last_node;
	t_list	*tmp;

	tmp = *stack_b;
	if (!(*stack_b) || !(*stack_b)->next || n == 0)
		return ;
	write(1, "rrb\n", 4);
	while (tmp->next->next)
		tmp = tmp->next;
	last_node = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_b, last_node);
	if (n > 0)
		rrb(stack_b, n - 1);
}
