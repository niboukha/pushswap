/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:14:09 by niboukha          #+#    #+#             */
/*   Updated: 2023/04/27 12:23:02 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	free_arr(t_longest	*lis, t_longest	*tmp_list)
{
	int	j;

	j = 0;
	while (j < 3)
		free (lis->arr[j++]);
	j = 0;
	while (j < 3)
		free (tmp_list->arr[j++]);
}

void	init_arr_tmp(t_longest	*tmp_list)
{
	int	i;

	i = 0;
	while (i < 3)
		tmp_list->arr[i++] = 0;
}
