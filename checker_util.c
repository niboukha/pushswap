/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:09:38 by niboukha          #+#    #+#             */
/*   Updated: 2023/04/01 03:12:42 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ch_sa(t_list **stack_a)
{
	t_list	*new;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	new = (*stack_a)->next;
	(*stack_a)->next = (*stack_a)->next->next;
	ft_lstadd_front(stack_a, new);
}

void	ch_sb(t_list **stack_b)
{
	t_list	*new;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	new = (*stack_b)->next;
	(*stack_b)->next = (*stack_b)->next->next;
	ft_lstadd_front(stack_b, new);
}

void	ch_ss(t_list **stack_a, t_list **stack_b)
{
	ch_sa(stack_a);
	ch_sb(stack_b);
}

void	ch_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*new;

	if (!(*stack_b))
		return ;
	new = *stack_b;
	*stack_b = (*stack_b)->next;
	new->next = NULL;
	ft_lstadd_front(stack_a, new);
}

void	ch_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*new;

	if (!(*stack_a))
		return ;
	new = *stack_a;
	*stack_a = (*stack_a)->next;
	new->next = NULL;
	ft_lstadd_front(stack_b, new);
}
