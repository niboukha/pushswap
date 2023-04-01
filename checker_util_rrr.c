/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util_rrr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:11:58 by niboukha          #+#    #+#             */
/*   Updated: 2023/04/01 02:18:50 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ch_rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*last_node_a;
	t_list	*last_node_b;
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	if (!(*stack_a) || !(*stack_a)->next
		|| !(*stack_b) || !(*stack_b)->next)
		return ;
	while (tmp_a->next->next)
		tmp_a = tmp_a->next;
	while (tmp_b->next->next)
		tmp_b = tmp_b->next;
	last_node_a = tmp_a->next;
	last_node_b = tmp_b->next;
	tmp_a->next = NULL;
	tmp_b->next = NULL;
	ft_lstadd_front(stack_a, last_node_a);
	ft_lstadd_front(stack_b, last_node_b);
}
