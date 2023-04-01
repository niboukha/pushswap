/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:19:36 by niboukha          #+#    #+#             */
/*   Updated: 2023/04/01 02:40:07 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ch_ra(t_list **stack_a)
{
	t_list	*first_node;

	if (!(*stack_a))
		return ;
	first_node = *stack_a;
	*stack_a = (*stack_a)->next;
	first_node->next = NULL;
	ft_lstadd_back(stack_a, first_node);
}

void	ch_rb(t_list **stack_b)
{
	t_list	*first_node;

	if (!(*stack_b))
		return ;
	first_node = *stack_b;
	*stack_b = (*stack_b)->next;
	first_node->next = NULL;
	ft_lstadd_back(stack_b, first_node);
}

void	ch_rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_node_a;
	t_list	*first_node_b;

	if (!(*stack_a) || !(*stack_b))
		return ;
	first_node_a = *stack_a;
	first_node_b = *stack_b;
	*stack_a = (*stack_a)->next;
	*stack_b = (*stack_b)->next;
	first_node_a->next = NULL;
	first_node_b->next = NULL;
	ft_lstadd_back(stack_a, first_node_a);
	ft_lstadd_back(stack_b, first_node_b);
}

void	ch_rra(t_list **stack_a)
{
	t_list	*last_node;
	t_list	*tmp;

	tmp = *stack_a;
	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	while (tmp->next->next)
		tmp = tmp->next;
	last_node = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_a, last_node);
}

void	ch_rrb(t_list **stack_b)
{
	t_list	*last_node;
	t_list	*tmp;

	tmp = *stack_b;
	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	while (tmp->next->next)
		tmp = tmp->next;
	last_node = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_b, last_node);
}
