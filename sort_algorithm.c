/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:21:51 by niboukha          #+#    #+#             */
/*   Updated: 2023/03/31 00:40:28 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bound	minimum_maximum_stack_a(t_list *tmp_a, int val,
	t_bound j_tmp, t_bound j_min)
{
	t_bound	j;
	t_norm	t;

	t.size = ft_lstsize(tmp_a);
	t.max = get_max(tmp_a);
	j.max = t.size;
	j.min = 0;
	while (tmp_a)
	{
		if (tmp_a->data > val && (tmp_a->data <= t.max || !j.min))
		{
			t.max = tmp_a->data;
			j_tmp = j;
		}
		if (tmp_a->data < t.min || !j.min)
		{
			t.min = tmp_a->data;
			j_min = j;
		}
		j.max = t.size - ++j.min;
		tmp_a = tmp_a->next;
	}
	if (t.max < val)
		return (j_min);
	return (j_tmp);
}

int	combinaison(t_bound i, t_bound j, int min)
{
	t_combinaison	comb;

	comb.a = _max(i.min, j.min);
	comb.b = _max(i.max, j.max);
	comb.c = i.min + j.max;
	comb.d = i.max + j.min;
	if (comb.a <= comb.b && comb.a <= comb.c
		&& comb.a <= comb.d && comb.a < min)
		return (comb.a);
	if (comb.b <= comb.a && comb.b <= comb.c
		&& comb.b <= comb.d && comb.b < min)
		return (comb.b);
	if (comb.c <= comb.b && comb.c <= comb.a
		&& comb.c <= comb.d && comb.c < min)
		return (comb.c);
	if (comb.d < min)
		return (comb.d);
	return (min);
}

void	instraction_c_d(t_list **stack_a, t_list **stack_b,
	t_bound i, t_bound j)
{
	t_combinaison	comb;

	comb.a = _max(i.min, j.min);
	comb.b = _max(i.max, j.max);
	comb.c = i.min + j.max;
	comb.d = i.max + j.min;
	if (comb.c <= comb.b && comb.c <= comb.a && comb.c <= comb.d)
	{
		ra(stack_a, i.min);
		rrb(stack_b, j.max);
	}
	else
	{
		rra(stack_a, i.max);
		rb(stack_b, j.min);
	}
}

void	instruction(t_list **stack_a, t_list **stack_b, t_bound i, t_bound j)
{
	t_combinaison	comb;

	comb.a = _max(i.min, j.min);
	comb.b = _max(i.max, j.max);
	comb.c = i.min + j.max;
	comb.d = i.max + j.min;
	if (comb.a <= comb.b && comb.a <= comb.c && comb.a <= comb.d)
	{
		rr(stack_a, stack_b, _min(i.min, j.min));
		if (i.min > j.min)
			ra(stack_a, i.min - j.min);
		else
			rb(stack_b, j.min - i.min);
	}
	else if (comb.b <= comb.a && comb.b <= comb.c && comb.b <= comb.d)
	{
		rrr(stack_a, stack_b, _min(i.max, j.max));
		if (i.max > j.max)
			rra(stack_a, i.max - j.max);
		else
			rrb(stack_b, j.max - i.max);
	}
	else
		instraction_c_d(stack_a, stack_b, i, j);
	pa(stack_a, stack_b, 1);
}

void	minimum_maximum_stack_b(t_list **stack_a, t_list **stack_b)
{
	t_norm_b	bound;
	t_list		*tmp_b;
	int			size;
	int			min;

	min = INT_MAX;
	size = ft_lstsize(*stack_b);
	bound.i.min = 0;
	bound.i.max = size * (size > 1);
	tmp_b = *stack_b;
	while (tmp_b)
	{
		bound.j = minimum_maximum_stack_a(*stack_a,
				tmp_b->data, bound.i, bound.i);
		if (combinaison(bound.j, bound.i, min) < min)
		{
			min = combinaison(bound.j, bound.i, min);
			bound.a = bound.j;
			bound.b = bound.i;
		}
		bound.i.min++;
		bound.i.max = size - bound.i.min;
		tmp_b = tmp_b->next;
	}
	instruction(stack_a, stack_b, bound.a, bound.b);
}
