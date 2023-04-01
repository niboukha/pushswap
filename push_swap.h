/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:26:57 by niboukha          #+#    #+#             */
/*   Updated: 2023/04/01 02:20:48 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct t_list
{
	int					data;
	int					index;
	struct t_list		*next;
}						t_list;

typedef struct t_longest
{
	int		*arr[3];
	int		*arr_lis;
	int		length;
	int		a;
	int		max;
	int		size;
}			t_longest;

typedef struct t_bound
{
	int	max;
	int	min;
}		t_bound;

typedef struct t_combinaison
{
	int	a;
	int	b;
	int	c;
	int	d;
}		t_combinaison;

typedef struct t_norm
{
	int	size;
	int	max;
	int	min;
}		t_norm;

typedef struct t_norm_b
{
	t_bound	i;
	t_bound	j;
	t_bound	a;
	t_bound	b;
}			t_norm_b;

char	**ft_split(char const *s, char c);
int		ft_atoi(char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(int data);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b, int n);
void	pb(t_list **stack_a, t_list **stack_b, int n);
void	ra(t_list **stack_a, int n);
void	rb(t_list **stack_b, int n);
void	rr(t_list **stack_a, t_list **stack_b, int n);
void	rra(t_list **stack_a, int n);
void	rrb(t_list **stack_b, int n);
void	rrr(t_list **stack_a, t_list **stack_b, int n);
int		largest_element(t_list *stack_a);
void	indexing_stack(t_list *stack_a);
void	longest_increasing_subsequence(t_list **stack_a, t_list **stack_b);
void	fill_arrays(t_list **stack_a, t_longest	*lis);
void	largest_array(t_longest *lis);
void	push_in_stack_b(t_longest *arr, t_list **stack_a,
			t_list **stack_b, int flag);
void	minimum_maximum_stack_b(t_list **stack_a, t_list **stack_b);
int		combinaison(t_bound i, t_bound j, int min);
void	instruction(t_list **stack_a, t_list **stack_b, t_bound i, t_bound j);
void	clear_stack_a(t_list **stack_a);
void	re_push_stack_b(t_list **stack_a, int	*flag, int *size);
int		check_double(t_list *stack_a);
int		handel_numbers(char **str);
int		ft_atoi(char *str);
void	sort_2_algo(t_list **stack_a);
void	sort_3_algo(t_list **stack_a);
void	sort_5_algo(t_list **stack_a, t_list **stack_b);
int		get_max(t_list *stack_a);
int		_max(int x, int y);
int		_min(int x, int y);
void	sort_5(t_list **stack_a, t_list **stack_b);
void	fill_arrays_sub_len(t_longest *tmp_list);

void	ft_checker(t_list **stack_a);

#endif