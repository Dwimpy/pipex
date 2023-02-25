# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 14:38:01 by arobu             #+#    #+#              #
#    Updated: 2023/02/25 14:06:12 by arobu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME			= pipex
INCLUDE			= -I ./include/ -I./libft/include/
DSYM			= $(NAME).dSYM
SRC_DIR			= ./src
OBJ_DIR			= ./obj
LIBFT_FOLDER	= ./libft
LIBFT_LIB		= ./libft/libft.a
MAIN_FILE		= main.c
# Compiler

CC			= gcc
CFLAGS		= -g3 -Wall -Werror -Wextra #-fsanitize=address -g3 #-Wall -Werror -Wextra 
LDLFLAGS	= -L./libft/ -lft

#Archive and Remove

RM			= rm -f
AR			= ar rcs

# Colors

DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Sources

PIPEX_SRCS	=	$(wildcard $(SRC_DIR)/*.c)
PIPEX_OBJS	= 	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(PIPEX_SRCS))

all:	libft	$(NAME)

$(NAME): $(PIPEX_OBJS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $(PIPEX_OBJS) $(MAIN_FILE) $(LDLFLAGS)
	@echo "$(CYAN)Pipex built successfully.$(DEF_COLOR)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@ echo "$(MAGENTA) Compiling file $<.$(DEF_COLOR)"
	@ $(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ 

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

libft:
			@make all -C $(LIBFT_FOLDER) -s

 clean:
			@$(RM) -rdf $(OBJ_DIR)
			@$(RM) -rdf $(DSYM)
			@echo "$(YELLOW)Fractol$(DEF_COLOR) $(CYAN)successfully cleaned!$(DEF_COLOR)"

fclean:		clean
			@make fclean -C $(LIBFT_FOLDER)
			@$(RM) -f $(NAME)
			@echo "$(YELLOW)All$(DEF_COLOR) $(CYAN)objects successfully cleaned!$(DEF_COLOR)"

re:			fclean all

relibft:
			@make re -C $(LIBFT_FOLDER)

.PHONY:		all relibft libft clean fclean re norm
