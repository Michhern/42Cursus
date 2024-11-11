# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: michhern <michhern@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 15:41:13 by michhern          #+#    #+#              #
#    Updated: 2024/11/11 16:15:23 by michhern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Standard
NAME		= fractol

#Directorios
INC_DIR 	= inc/
SERC_DIR 	= srcs/
OBJ_DIR 	= obj/

#Compiladores y Flags
MLX			= ./minilibx-linux
CC 			= cc
CFLAGS 		= -Wall -Werror -Wextra -I$(INC_DIR) -fsanitize=address
LDFLAGS		= -fsanitize=address
RM			= rm -rf

SRCS		= $(SERC_DIR)events.c \
				$(SERC_DIR)init.c \
				$(SERC_DIR)main.c \
				$(SERC_DIR)math_utils.c \
				$(SERC_DIR)render.c \
				$(SERC_DIR)string_utils.c

OBJ			= $(patsubst $(SERC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

#Rules
make:
	@make all

$(MLX):
	@make -C ./minilibx-linux

all: $(NAME)
	@make -C ./minilibx-linux

$(NAME): $(MLX) $(OBJ)
	$(CC) $(OBJ) $(MLX) $(LDFLAGS) -o $(NAME)

#Compilar archivos objetos a partir de los archivos fuentes
$(OBJ_DIR)%.o: $(SERC_DIR)%.c Makefile
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -rf $(OBJ_DIR)
	@make clean -C ./minilibx-linux

fclean: clean
	$(RM) $(NAME)
	$(RM) $(MLX)

re: fclean all

.PHONY: all clean fclean re