# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niboukha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 14:48:57 by niboukha          #+#    #+#              #
#    Updated: 2023/04/01 14:42:10 by niboukha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

NAME_BONUS = checker

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = hundling_functions.c push_swap.c ft_calloc.c ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c\
	ft_lstnew.c ft_lstsize.c ft_split.c ft_strcmp.c indexing_stack.c sort_algorithm.c\
	longest_incr_sub.c push_in_stack_b.c clear_stack_a.c sort_2_3_5.c handling_functions_2.c\
	handling_functions_rrb.c ft_strlen.c

BONUS = checker.c ft_calloc.c ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c\
	ft_lstnew.c ft_lstsize.c ft_split.c ft_strcmp.c handling_functions_2.c\
	handling_functions_rrb.c hundling_functions.c get_next_line.c\
	get_next_line_utils.c checker_util.c checker_util_2.c checker_util_rrr.c\
	handel_checker.c ft_strlen.c

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
