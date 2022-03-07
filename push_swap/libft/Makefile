# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wokim <wokim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/02 15:58:25 by wokim             #+#    #+#              #
#    Updated: 2022/03/07 16:24:00 by wokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
AR = ar
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = rc
NAME = libft.a
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	   ft_isprint.c ft_toupper.c ft_tolower.c ft_isspace.c\
	   ft_strlen.c ft_strlcpy.c ft_strlcat.c \
	   ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c \
	   ft_memset.c ft_bzero.c ft_memmove.c \
	   ft_memcpy.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	   ft_calloc.c ft_strdup.c \
	   ft_substr.c ft_strjoin.c ft_strtrim.c \
	   ft_split.c ft_itoa.c ft_strmapi.c \
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	   ft_atod.c ft_issign.c ft_strcmp.c

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	   ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

RM = rm -f

all : $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJS)
	@$(AR) $(ARFLAGS) $@ $(OBJS)
	@ranlib $@

bonus : $(NAME) $(BONUS_OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(BONUS_OBJS)

clean :
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all
