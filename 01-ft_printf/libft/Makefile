# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kim-wonjin <kim-wonjin@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 21:52:19 by wokim             #+#    #+#              #
#    Updated: 2021/08/30 00:10:03 by kim-wonjin       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAG = -Wall -Wextra -Werror

INCLUDES = ./libft.h

SRC_PART1 = \
	./ft_strlen.c	\
	./ft_strchr.c	\
	./ft_isdigit.c	\
	./ft_putstr_fd.c
	
SRCS = \
	$(SRC_PART1)

OBJS = $(SRCS:.c=.o)

OBJ_FILES = $(OBJS)

.PHONY: all
all : $(NAME)

$(NAME): $(OBJ_FILES)
	ar -rcs $@ $^

.PHONY: clean
clean :
	rm -f $(OBJS)

.PHONY: fclean
fclean : clean
	rm -f $(NAME)

.PHONY: re
re : fclean all

.c.o : $(SRCS) $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
