# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: michhern <michhern@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 11:48:58 by michhern          #+#    #+#              #
#    Updated: 2024/09/11 13:30:06 by michhern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Standard
NAME		= push_swap

#Directorios
LIBFT		= ./libft/libft.a
INC_DIR		= inc/
SERC_DIR	= srcs/
OBJ_DIR		= obj/

#Compiladores y Flags
CC			= gcc
CFLAGS 		= -Wall -Werror -Wextra -I$(INC_DIR) -fsanitize=address
LDFLAGS		= -fsanitize=address
RM			= rm -rf

#Archivos fuentes
UTILS_DIR			= $(SERC_DIR)utils/push.c \
						$(SERC_DIR)utils/push_cost.c \
						$(SERC_DIR)utils/rev_rotate.c \
						$(SERC_DIR)utils/rotate.c \
						$(SERC_DIR)utils/sort_stacks.c \
						$(SERC_DIR)utils/sort_three.c \
						$(SERC_DIR)utils/swap.c
						
PUSH_SWAP_DIR		= $(SERC_DIR)push_swap/handle_errors.c \
						$(SERC_DIR)push_swap/from_a_to_b.c \
						$(SERC_DIR)push_swap/from_b_to_a.c \
						$(SERC_DIR)push_swap/push_swap.c \
						$(SERC_DIR)push_swap/split.c \
						$(SERC_DIR)push_swap/stack_init.c \
						$(SERC_DIR)push_swap/stack_utils.c 

#Concatenar todos los archivos de origen
SRCS				= $(UTILS_DIR) $(PUSH_SWAP_DIR)

#Aplicar la sustitución de patrones a cada fichero fuente en SRC y 
# producir una lista correspondiente de ficheros objeto en OBJ_DIR
OBJ					= $(patsubst $(SERC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

#Rules
make:
	@make all
 
$(LIBFT):			
	@make -C ./libft

all: $(NAME)
	@make -C ./libft

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIBFT) $(LDFLAGS) -o $(NAME)

#Compilar archivos objeto a partir de archivos fuente
$(OBJ_DIR)%.o: $(SERC_DIR)%.c Makefile
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -rf $(OBJ_DIR)
	@make clean -C ./libft

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: fclean all

#Los objetivos falsos representan acciones, no archivos
.PHONY: all clean fclean re
