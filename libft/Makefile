# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 01:17:05 by arobu             #+#    #+#              #
#    Updated: 2022/11/19 23:19:18 by arobu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME			= libft.a
INCLUDE			= include/

FT_PRINTF_SDIR	= ./src/ft_printf
FT_STDLIB_SDIR	= ./src/ft_stdlib

OBJ_DIR			= ./obj/
FT_PRINTF_OBJ	= ./obj/ft_printf
FT_STDLIB_OBJ	= ./obj/ft_stdlib

FT_STDLIB_LIB	= ft_stdlib.a
FT_PRINTF_LIB	= ft_printf.a
LIBFT_LIB		= libft.a
# Compiler

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I

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

#Sources

STDLIB_SRCS	=	$(wildcard $(FT_STDLIB_SDIR)/*.c)
STDLIB_OBJS	= 	$(patsubst $(FT_STDLIB_SDIR)/%.c, $(FT_STDLIB_OBJ)/%.o, $(STDLIB_SRCS))

PRINTF_SRCS	=	$(wildcard $(FT_PRINTF_SDIR)/*.c)
PRINTF_OBJS	= 	$(patsubst $(FT_PRINTF_SDIR)/%.c, $(FT_PRINTF_OBJ)/%.o, $(PRINTF_SRCS))


all:	libft printf $(NAME)

$(NAME):
					@echo "$(CYAN) Creating libft library.$(DEF_COLOR)"
					@ar rcs libft.a $(STDLIB_OBJS) $(PRINTF_OBJS)
					@echo "$(CYAN) $(NAME) successfully created.$(DEF_COLOR)" 

libft:		$(FT_STDLIB_LIB)

$(FT_STDLIB_LIB):	$(STDLIB_OBJS)

$(FT_STDLIB_OBJ)%.o:	$(FT_STDLIB_SDIR)%.c | $(FT_STDLIB_OBJ)
						@echo "$(MAGENTA) Compiling file: $< $(DEF_COLOR)"
						@ $(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(FT_STDLIB_OBJ): | $(OBJ_DIR)
					mkdir -p $(FT_STDLIB_OBJ)

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

printf:		$(FT_PRINTF_LIB)

$(FT_PRINTF_LIB):	$(PRINTF_OBJS)

$(FT_PRINTF_OBJ)%.o:	$(FT_PRINTF_SDIR)%.c | $(FT_PRINTF_OBJ)
						@echo "$(MAGENTA) Compiling file: $< $(DEF_COLOR)"
						@ $(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(FT_PRINTF_OBJ): | $(OBJ_DIR)
					mkdir -p $(FT_PRINTF_OBJ)

clean:
			@$(RM) -rdf $(OBJ_DIR) 
			@echo "$(CYAN)Object files successfullly cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) $(FT_STDLIB_LIB) 
			@$(RM) $(FT_PRINTF_LIB) 
			@$(RM) -f $(NAME)
			@echo "$(CYAN)Libraries successfully cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(RED)Files have been cleaned and project has been rebuilt!$(DEF_COLOR)"

bonus: 	$(NAME)  

norm:
			@norminette $(SRC) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true
		
.PHONY:		all clean fclean re norm