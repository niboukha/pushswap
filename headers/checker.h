/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:00:02 by niboukha          #+#    #+#             */
/*   Updated: 2023/04/01 03:24:50 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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
void	ch_sa(t_list **stack_a);
void	ch_sb(t_list **stack_b);
void	ch_ss(t_list **stack_a, t_list **stack_b);
void	ch_pa(t_list **stack_a, t_list **stack_b);
void	ch_pb(t_list **stack_a, t_list **stack_b);
void	ch_ra(t_list **stack_a);
void	ch_rb(t_list **stack_b);
void	ch_rr(t_list **stack_a, t_list **stack_b);
void	ch_rra(t_list **stack_a);
void	ch_rrb(t_list **stack_b);
void	ch_rrr(t_list **stack_a, t_list **stack_b);
void	ft_checker(t_list **stack_a, t_list **stack_b);
void	handel_args(char **split_args, t_list **stack_a, int i);
int		is_sorted(t_list **stack_a);
int		check_double(t_list *stack_a);
int		handel_numbers(char **str);
int		ft_atoi(char *str);

#endif