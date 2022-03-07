# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wokim <wokim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 16:27:38 by wokim             #+#    #+#              #
#    Updated: 2022/03/07 16:27:38 by wokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		= ./srcs/push_swap.c \
			./srcs/parsing/array.c \
			./srcs/parsing/util.c \
			./srcs/operations/op_swap_push.c \
			./srcs/operations/op_rotate.c \
			./srcs/operations/op_reverse_rotate.c \
			./srcs/algorithm/sort.c \
			./srcs/algorithm/sort_util.c \
			./srcs/algorithm/rotate.c \
			./srcs/algorithm/rotate_util.c \
			./srcs/algorithm/rotate_op.c
			
BSRCS		= ./bonus/srcs/main.c \
			./bonus/srcs/checker.c \
			./bonus/srcs/do_operation.c \
			./bonus/srcs/free.c \
			./bonus/srcs/parsing/array.c \
			./bonus/srcs/parsing/util.c \
			./bonus/srcs/operations/op_swap_push.c \
			./bonus/srcs/operations/op_rotate.c \
			./bonussrcs/operations/op_reverse_rotate.c \
			./bonus/srcs/gnl/get_next_line_bonus.c \
			./bonus/srcs/gnl/get_next_line_utils_bonus.c

OBJS		= $(SRCS:%.c=%.o)

BOBJS		= $(BSRCS:%.c=%.o)

LIBC		= ar rc

#FLAGS		= -Wall -Wextra -Werror
FLAGS		= -g -Wall -Wextra -Werror

all			:	$(NAME)

bonus		:	re
				make fclean -C ./bonus
				make all -C ./bonus

$(NAME)		:	$(OBJS)
		make all -C $(LIBFT)/
		gcc -o $(NAME) $(OBJS) -Llibft -lft

%.o			:	%.c
		gcc $(FLAGS) -c $^ -I./ -o $@


clean		:
		rm -f $(OBJS)
		rm -f $(BOBJS)
		make clean -C $(LIBFT)

fclean		:	clean
		rm -f $(NAME)
		rm -f $(LIBFT_LIB)
		make fclean -C $(LIBFT)
		@if [ -f ./bonus/checker ]; then rm -f ./bonus/checker; fi;

re			:	fclean all

.PHONY		:	all clean fclean re bonus
