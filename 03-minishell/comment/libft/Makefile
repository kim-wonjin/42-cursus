# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshin <sshin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 20:46:54 by sshin             #+#    #+#              #
#    Updated: 2022/02/10 20:46:55 by sshin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFAGS = -Wall -Wextra -Werror
# CFLAGS	+= -g
# CFLAGS	+= -fsanitize=address

# =============================================================================
# Header
# =============================================================================

HEADER = libft.h
OPTION = -I $(HEADER)

# =============================================================================
# Source
# =============================================================================

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
	ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
	ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c \
	ft_substr.c ft_strtrim.c ft_strjoin.c ft_split.c ft_itoa.c ft_strmapi.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
	ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
	ft_lstclear.c ft_lstiter.c ft_lstmap.c

# =============================================================================
# Object
# =============================================================================

OBJECTS = $(SRC:.c=.o)

# =============================================================================
# Color
# =============================================================================

RED			= \033[0;31m
GRN			= \033[0;32m
BBLU		= \033[1;34m
CYAN		= \033[0;36m
BRED		= \033[1;31m
BYEL		= \033[1;33m
BLK			= \033[0;30m
EOC			= \033[0;0m

# =============================================================================
# Rule
# =============================================================================

.PHONY	: all
all		: $(NAME)

$(NAME)	: $(OBJECTS)
	@ar rc $@ $(OBJECTS)
	@echo "\n$(NAME): $(GRN)objects were created$(EOC)"
	@echo "$(NAME): $(GRN)$(NAME) was created$(EOC)"

%.o:%.c	$(HEADER)
	@$(CC) $(CFAGS) -o $@ -c $< -I $(HEADER)
	@echo "$(GRN).$(EOC)\c"

.PHONY	: clean
clean	:
	@rm -f $(OBJECTS)
	@echo "$(NAME): $(RED)objects were deleted$(EOC)"

.PHONY	: fclean
fclean	: clean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(EOC)"

.PHONY	: re
re : fclean all
