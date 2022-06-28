# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshin <sshin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 20:43:08 by sshin             #+#    #+#              #
#    Updated: 2022/02/11 21:45:02 by hyseo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= minishell
CC 				= gcc
CFLAGS 			= -Wall -Wextra -Werror
# CFLAGS	+= -g
# CFLAGS	+= -fsanitize=address
RM				= rm -rf

# READLINE_LIB	= -lreadline -L/usr/local/opt/readline/lib
# READLINE_INC	= -I/usr/local/opt/readline/include

READLINE_LIB	= -lreadline -L/Users/hyseo/.brew/opt/readline/lib
READLINE_INC	= -I/Users/hyseo/.brew/opt/readline/include

# =============================================================================
# Archieve
# =============================================================================

LIBFT			= libft.a
LIBFT_DIR		= libft

# =============================================================================
# Source
# =============================================================================

SRC_DIR 	= srcs
SRC 		= srcs/minishell.c srcs/utils/utils.c srcs/parser/parse.c \
			srcs/execute/exec.c srcs/utils/error_management.c \
			srcs/execute/ft_cd.c srcs/execute/ft_exit.c \
			srcs/execute/ft_env.c srcs/execute/ft_pwd.c \
			srcs/execute/ft_export.c srcs/execute/export_utils.c \
			srcs/signal_handle.c srcs/parser/alloc_token.c \
			srcs/parser/cmd_split.c srcs/parser/get_parse_size.c \
			srcs/redirection/redir_chk.c srcs/utils/ft_getenv.c \
			srcs/redirection/redirect.c srcs/redirection/redirect_check.c \
			srcs/execute/ft_echo.c srcs/execute/ft_unset.c \
			srcs/execute/exec_utils.c srcs/utils/utils2.c \
			srcs/parser/ft_alloc_word.c srcs/parser/d_quote_cnt.c \
			srcs/parser/alloc_env_util.c srcs/parser/ft_split_cnt.c

# =============================================================================
# Object
# =============================================================================

OBJ_DIR 	= objs
OBJ 		= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

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

.PHONY		: all
all			: $(NAME)

$(NAME)		: $(LIBFT) $(OBJ)
			@$(CC) $(CFLAGS) -o $@ $(OBJ) $(READLINE_LIB) $(READLINE_INC) \
			$(LIBFT)
			@echo "\n$(NAME): $(GRN)objects were created$(EOC)"
			@echo "$(NAME): $(GRN)$(NAME) was created$(EOC)"

$(LIBFT)	:
			@cd $(LIBFT_DIR); make
			@cp $(LIBFT_DIR)/$(LIBFT) ./
			@mkdir -p $(OBJ_DIR)/execute
			@mkdir -p $(OBJ_DIR)/parser
			@mkdir -p $(OBJ_DIR)/redirection
			@mkdir -p $(OBJ_DIR)/utils

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
			@$(CC) $(CFLAGS) -c $< -o $(<:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) \
			$(READLINE_INC)
			@echo "$(GRN).$(EOC)\c"

.PHONY		: clean
clean		:
			@cd $(LIBFT_DIR); make clean
			@$(RM) $(OBJ) $(OBJ_DIR)
			@echo "$(NAME): $(RED)objects were deleted$(EOC)"

.PHONY		: fclean
fclean 		: clean
			@cd $(LIBFT_DIR); make fclean
			@$(RM) $(NAME) $(LIBFT)
			@echo "$(NAME): $(RED)$(NAME) was deleted$(EOC)"

.PHONY		: re
re			: fclean all
