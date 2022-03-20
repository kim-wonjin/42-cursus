# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 15:47:17 by jinyoo            #+#    #+#              #
#    Updated: 2022/03/18 16:23:20 by jinyoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

NAME = so_long

SRCS_DIR = ./src
SRCS =	src/main.c \
		src/init.c \
		src/move_player.c \
		src/draw.c \
		src/check_map.c
OBJS = $(SRCS:.c=.o)

# 외부라이브러리 모음 =================================================

MLX_NAME = mlx
MLX_DIR = ./include/minilibx_opengl_20191021

GNL_NAME = gnl
GNL_DIR = ./include/get_next_line

# 외부라이브러리 모음 ===================================================
.PHONY : all clean fclean re

$(NAME) : $(OBJS)
	$(MAKE) -C $(MLX_DIR) all
	$(MAKE) -C $(GNL_DIR) all
	$(CC) $(CFLAGS) -L$(MLX_DIR) -l$(MLX_NAME) \
			-L$(GNL_DIR) -l$(GNL_NAME) \
			-framework OpenGL -framework AppKit $^ -o $@

$(SRCS_DIR)/%.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(GNL_DIR) -c $< -o $@

all : $(NAME)

clean :
	@rm -rf $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean

fclean :
	@rm -rf $(NAME) $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(GNL_DIR) fclean

re : fclean all
