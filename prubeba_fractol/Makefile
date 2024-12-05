# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: michhern <michhern@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 15:41:13 by michhern          #+#    #+#              #
#    Updated: 2024/11/19 11:49:06 by michhern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
RESET			= "\033[0m"
BLACK			= "\033[30m"    # Black
RED				= "\033[31m"    # Red
GREEN			= "\033[32m"    # Green
YELLOW			= "\033[33m"    # Yellow
BLUE			= "\033[34m"    # Blue
MAGENTA			= "\033[35m"    # Magenta
CYAN			= "\033[36m"    # Cyan
WHITE			= "\033[37m"    # White


#Standard
NAME		= fractol

#Compiladores y Flags
CC 			= cc
CFLAGS 		= -Wall -Werror -Wextra -I$(INC_DIR) -fsanitize=address
LDFLAGS		= -fsanitize=address
RM			= rm -rf

#Files and paths #HEADER
INC_DIR 	= inc/
INC_FILES	= fractol.h
INC			= $(addprefix $(INC_DIR), $(INC_FILES))

#SRCS The main Files for the project
SRCS_DIR 	= srcs/
SRCS_FILES	= events.c \
				init.c \
				main.c \
				math_utils.c \
				render.c \
				string_utils.c

SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS_DIR 	= objs/
OBJS_SRCS	= $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

#MINILIB
MLB_DIR		= mlx-linux/
MLB_FILES	= $(MLB_DIR)libmlx.a
MLB_FLAGS	= -L$(MLB_DIR) -lmlx -lX11 -lXext -lm

#Rules
all: $(NAME)

#Compilar archivos objetos a partir de los archivos fuentes
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INC) Makefile
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para crear el binario principal
$(NAME): $(OBJS_SRCS) $(MLB_FILES) Makefile
	@echo $(CYAN) " - Building $(NAME)..." $(RESET)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS_SRCS) $(MLB_FLAGS) $(MLB_FILES) -o $(NAME)
	@echo $(GREEN) " - Built $(NAME)!" $(RESET)

# Compilar MiniLibX
$(MLB_FILES):
	@echo $(CYAN) " - Building MiniLibX..." $(RESET)
	@make -C $(MLB_DIR)
	@echo $(GREEN) " - MiniLibX built!" $(RESET)

# Limpiar objetos
clean:
	$(RM) -rf $(OBJS_SRCS)
	@echo $(RED) " - Cleaned object files!" $(RESET)
	@make clean -C $(MLB_DIR)

# Limpiar todo
fclean: clean
	$(RM) $(NAME)
	@echo $(RED) " - Cleaned everything!" $(RESET)

re: fclean all

.PHONY: all clean fclean re