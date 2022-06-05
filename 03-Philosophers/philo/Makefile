# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wokim <wokim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 20:01:45 by wokim             #+#    #+#              #
#    Updated: 2022/05/19 19:17:06 by wokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	philo
CC					=	gcc
CFLAGS				=	-Wall -Werror -Wextra
# CFLAGS += -g
# CFLAGS += -fsanitize=address
RM					=	rm
RMFLAGS				=	-rf

#HEADERS
HEADER				=	./includes/

# SOURCES
SOURCES_DIRECTORY	=	./sources/
SOURCES_LIST		=	main.c			\
						print.c			\
						status.c		\
						terminate.c		\
						time.c			\
						libft/libft.c	\
						libft/libft2.c	\
						libft/libft3.c
SOURCES				=	$(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

# OBJECTS
OBJECTS				=	$(SOURCES:.c=.o)

# COLORS
RED					=	\033[0;31m
GRN					=	\033[0;32m
BBLU				=	\033[1;34m
CYAN				=	\033[0;36m
BRED				=	\033[1;31m
BYEL				=	\033[1;33m
BLK					=	\033[0;30m
EOC					=	\033[0;0m

.PHONY		:	all
all			:	$(NAME)

$(NAME)		:	$(OBJECTS)
				@$(CC) $(CFALGS) -I $(HEADER) -o $(NAME) $(OBJECTS)
				@echo "\n$(NAME): $(GRN)objects were created$(EOC)"
				@echo "$(NAME): $(GRN)$(NAME) was created$(EOC)"

%.o			:	%.c
				@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<
				@echo "$(GRN).$(EOC)\c"

.PHONY		:	clean
clean		:
				@$(RM) $(RMFLAGS) $(OBJECTS)
				@echo "$(NAME): $(RED)objects were deleted$(EOC)"

.PHONY		:	fclean
fclean		:	clean
				@$(RM) $(RMFLAGS) $(NAME)
				@echo "$(NAME): $(RED)$(NAME) was deleted$(EOC)"

.PHONY		:	re
re			:
	$(MAKE) fclean
	$(MAKE) all
