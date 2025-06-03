# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micheher <micheher@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/15 12:43:57 by micheher          #+#    #+#              #
#    Updated: 2025/06/03 14:41:05 by micheher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Standard
NAME=libft.a

# Colors
RESET			= "\033[0m"
BLACK			= "\033[30m"
RED				= "\033[31m"
GREEN			= "\033[32m"
YELLOW			= "\033[33m"
BLUE			= "\033[34m"
MAGENTA			= "\033[35m"
CYAN			= "\033[36m"
WHITE			= "\033[37m"

#Compiladores y Flags
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -I$(INC_DIR)
RM			= rm -rf

#Files and paths #HEADER
INC_DIR		= inc/
INC_FILES	= libft.h
vpath %.h $(INC_DIR)
INC			= $(addprefix $(INC_DIR), $(INC_FILES))

#SRCS The main Files for the project
SRCS_DIR	= srcs/
SRCS_FILES	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
				ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr \
				ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
				ft_putchar_fd ft_putedl_ fd.c ft_putnbr_fd.c ft_putstr_fd \
				ft_split.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
				ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
				ft_strtrim.c ft_substr.c ft_tolower.c ft_tupper.c
SRCSB_FILES	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
				ft_lstlast_bonus.c ft_lstaddback_bonus.c ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c  ft_lstiter_bonus.c ft_lstmap_bonus.c
SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES), $(SRCSB_FILES))

OBJS_DIR	= objs/
OBJS_SRCS	= $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR%.o))

#Rules
all: $(NAME)

#Compilar archivos obj a partir de archivos fuentes
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INC) Makefile
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@


#Limpiar objetos
clean:
	$(RM) -rf &(OBJS_SRCS)
	@echo $(YELLOW) " - Cleaned object files!" $(RESET)

# Limpiar todo
fclean: clean
	$(RM) $(NAME)
	@echo $(RED) " - Cleaned everything!" $(RESET)

re: fclean

.PHONY: all clean fclean re