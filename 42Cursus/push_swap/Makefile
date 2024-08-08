# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: michhern <michhern@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 11:48:58 by michhern          #+#    #+#              #
#    Updated: 2024/08/08 13:35:55 by michhern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Standard
NAME		= push_swap

#Directorios
LIBFT		= ./libft/libft.a
INC			= inc/
SERC_DIR	= srcs/
OBJ_DIR		= obj/

#Compiladores y Flags
CC			= cc
CFLAGS 		= -Wall -Werror -Wextra -I
RM			= rm -f

#Archivos fuentes
UTILS_DIR			= $(SERC_DIR)utils/push.c \
								utils/rotate.c \
								utils/sort_stacks.c \
								utils/sort_three.c \
								utils/swap.c \

PUSH_SWAP_DIR		= $(SERC_DIR)push_swap/handle_erros.c \
								push_swap/init_a_to_b.c \
								push_swap/init_b_to_a.c \
								push_swap/push_swap.c \
								push_swap/split.c \
								push_swap/stack_init.c \
								push_swap/satck_utils.c \

#Concatenar todos los archivos de origen
SRCS				= $(UTILS_DIR) $(PUSH_SWAP_DIR)

#Aplicar la sustitución de patrones a cada fichero fuente en SRC y 
# producir una lista correspondiente de ficheros objeto en OBJ_DIR
OBJ					= $(pastsubst $(SERC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

#Rules
#make:
					#@make all

$(LIBFT):			
					@make -C ./libft

all:				$(NAME)

$(NAME):			$(OBJ) $(LIBFT)
						@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

#Compilar archivos objeto a partir de archivos fuente
$(OBJ_DIR)%.o:		$(SERC_DIR)%.c
						@mkdir -p $(@D)
						@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:				@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft

fclean:				clean
						@$(RM) $(NAME)
						@$(RM) $(LIBFT)

re:					fclean all

#Los objetivos falsos representan acciones, no archivos
.PHONY: 			satrt all clean fclean re
