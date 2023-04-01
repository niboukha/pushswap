/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_incr_sub.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:56:40 by niboukha          #+#    #+#             */
/*   Updated: 2023/04/01 03:05:36 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	largest_array(t_longest *lis)
{
	int	i;

	i = 0;
	lis->arr_lis = malloc(sizeof (int) * lis->length);
	lis->max = lis->arr[1][0];
	while (i < lis->length)
	{
		if (lis->arr[1][i] > lis->max)
		{
			lis->max = lis->arr[1][i];
			lis->a = i;
			lis->size = lis->max;
		}
		i++;
	}
	i = 0;
	while (i < lis->length)
		lis->arr_lis[i++] = 0;
	while (--lis->max >= 0)
	{
		lis->arr_lis[lis->arr[0][lis->a]] = 1;
		lis->a = lis->arr[2][lis->a];
	}
}

void	fill_arrays(t_list **stack_a, t_longest	*lis)
{
	int		j;
	t_list	*tmp;

	tmp = *stack_a;
	lis->length = ft_lstsize(*stack_a);
	j = 0;
	while (j < 3)
		lis->arr[j++] = malloc(sizeof (int) * lis->length);
	j = 0;
	while (tmp)
	{
		lis->arr[0][j++] = tmp->data;
			tmp = tmp->next;
	}
	j = 0;
	while (j < lis->length)
	{
		lis->arr[1][j++] = 1;
		lis->arr[2][j++] = 0;
	}
}

void	fill_arrays_tmp(t_list **stack_a, t_longest *lis, t_longest *tmp_list)
{
	int	j;
	int	k;
	int	size_a;
	int	size;

	size = ft_lstsize(*stack_a);
	size_a = size;
	tmp_list->length = lis->length;
	j = 0;
	while (j < 3)
		tmp_list->arr[j++] = malloc(sizeof (int) * tmp_list->length);
	k = -1;
	while (++k < size_a)
	{
		tmp_list->arr[0][(k + (size_a - size + 1)) % size_a] = lis->arr[0][k];
		tmp_list->arr[1][k] = 1;
		tmp_list->arr[2][k] = 0;
	}
}

void	fill_arrays_sub_len(t_longest *tmp_list)
{
	int	i;
	int	j;

	i = 0;
	while (++i < tmp_list->length)
	{
		j = -1;
		while (++j < i)
		{
			if (tmp_list->arr[0][j] < tmp_list->arr[0][i]
				&& tmp_list->arr[1][i] <= tmp_list->arr[1][j] + 1)
			{
				tmp_list->arr[1][i] = tmp_list->arr[1][j] + 1;
				tmp_list->arr[2][i] = j;
			}
		}
	}
}

void	longest_increasing_subsequence(t_list **stack_a, t_list **stack_b)
{
	t_longest	lis;
	t_longest	tmp_list;
	int			size;
	int			size_a;

	fill_arrays(stack_a, &lis);
	size = ft_lstsize(*stack_a);
	size_a = size;
	while (size--)
	{
		fill_arrays_tmp(stack_a, &lis, &tmp_list);
		fill_arrays_sub_len(&tmp_list);
		largest_array(&tmp_list);
		if (lis.size < tmp_list.size)
		{
			lis.size = tmp_list.size;
			lis.arr_lis = tmp_list.arr_lis;
		}
	}
	if (size_a == lis.size + 1 && (*stack_a)->index == 0)
		exit(0);
	push_in_stack_b(&lis, stack_a, stack_b, 0);
}
