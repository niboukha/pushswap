# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niboukha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 14:48:57 by niboukha          #+#    #+#              #
#    Updated: 2023/04/27 12:37:23 by niboukha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = p_s/hundling_functions.c p_s/push_swap.c rec/ft_calloc.c rec/ft_lstadd_back.c rec/ft_lstadd_front.c rec/ft_lstlast.c\
	rec/ft_lstnew.c rec/ft_lstsize.c rec/ft_split.c rec/ft_strcmp.c p_s/indexing_stack.c p_s/sort_algorithm.c\
	p_s/longest_incr_sub.c p_s/push_in_stack_b.c p_s/clear_stack_a.c p_s/sort_2_3_5.c p_s/handling_functions_2.c\
	p_s/handling_functions_rrb.c rec/ft_strlen.c p_s/free_functions.c

BONUS = ch_ck/checker.c rec/ft_calloc.c rec/ft_lstadd_back.c rec/ft_lstadd_front.c rec/ft_lstlast.c\
	rec/ft_lstnew.c rec/ft_lstsize.c rec/ft_split.c rec/ft_strcmp.c rec/get_next_line.c\
	rec/get_next_line_utils.c ch_ck/checker_util.c ch_ck/checker_util_2.c ch_ck/checker_util_rrr.c\
	ch_ck/handel_checker.c rec/ft_strlen.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(BONUS:.c=.o)

all :$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

clean :
	rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY: all re clean fclean
