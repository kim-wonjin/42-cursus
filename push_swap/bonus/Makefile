# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wokim <wokim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 16:24:10 by wokim             #+#    #+#              #
#    Updated: 2022/03/07 16:50:22 by wokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= checker
LIBFT		= ../libft
LIBFT_LIB	= libft.a

SRCS		= ./srcs/main.c \
			./srcs/checker.c \
			./srcs/do_operation.c \
			./srcs/free.c \
			./srcs/parsing/array.c \
			./srcs/parsing/util.c \
			./srcs/operations/op_reverse_rotate.c \
			./srcs/operations/op_swap_push.c \
			./srcs/operations/op_rotate.c \
			./srcs/gnl/get_next_line_bonus.c \
			./srcs/gnl/get_next_line_utils_bonus.c

OBJS		= $(SRCS:%.c=%.o)

LIBC		= ar rc

CC			= gcc

FLAGS		= -g -Wall -Wextra -Werror
#FLAGS		= -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		make all -C $(LIBFT)/
		gcc -o $(NAME) $(OBJS) -L$(LIBFT) -lft

%.o			:	%.c
		gcc $(FLAGS) -c $^ -I./incs -o $@


clean		:
		rm -f $(OBJS)
		make clean -C $(LIBFT)

fclean		:	clean
		rm -f $(NAME)
		rm -f $(LIBFT_LIB)
		make fclean -C $(LIBFT)

re			:	fclean all

.PHONY		:	all clean fclean re bonus
