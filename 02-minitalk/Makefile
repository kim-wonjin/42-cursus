# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kim-wonjin <kim-wonjin@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/06 21:03:09 by kim-wonjin        #+#    #+#              #
#    Updated: 2022/02/07 03:42:21 by kim-wonjin       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME_SERVER	=	server
NAME_CLIENT	=	client
NAME		=	minitalk
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
# CFLAGS	+=	-g -fsanitize=address
AR		=	ar
ARFLAGS	=	-rcs
RM		=	rm -rf

# LIBRARY ARCHIVE
LIB_DIR		=	./libft/
LIB_NAME	=	libft.a
LIB		=	$(addprefix $(LIB_DIR), $(LIB_NAME))

# HEADERS
INCS_DIR	=	./incs/minitalk.h

# SOURCES
SRCS_SERVER	=	./srcs/server.c 
SRCS_CLIENT	=	./srcs/client.c 

# OBJECTS
OBJ_SERVER	=	$(SRCS_SERVER:.c=.o)
OBJ_CLIENT	=	$(SRCS_CLIENT:.c=.o)

# COLOR FLAGS
FG_BLACK   = \e[30m
FG_RED     = \e[31m
FG_GREEN   = \e[32m
FG_YELLOW  = \e[33m
FG_LBLUE   = \e[94m
FG_MAGENTA = \e[35m
NO_COLOR   = \e[0m

all : $(LIB_NAME) $(NAME)

$(NAME) : $(NAME_CLIENT) $(NAME_SERVER)

$(LIB_NAME) :
	@make -C $(LIB_DIR)

$(NAME_SERVER) : $(SRCS_SERVER) $(LIB)
	@$(CC) $(CFLAGS) $^ -o $@
	@printf "${FG_GREEN}Projcet make all succeeded!\n${NO_COLOR}"

$(NAME_CLIENT) : $(SRCS_CLIENT) $(LIB)
	@$(CC) $(CFLAGS) $^ -o $@
	@printf "${FG_GREEN}Projcet make all succeeded!\n${NO_COLOR}"

bonus : all

clean :
	@make clean -C $(LIB_DIR)
	@$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)
	@printf "${FG_YELLOW}Project make clean succeeded!\n${NO_COLOR}"

fclean : clean
	@make fclean -C $(LIB_DIR)
	@$(RM) $(NAME_SERVER) $(NAME_CLIENT)
	@printf "${FG_YELLOW}Project make fclean succeeded!\n${NO_COLOR}"

re : fclean all

.PHONY : all clean fclean re bonus