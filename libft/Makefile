# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: michhern <michhern@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 12:31:29 by michhern          #+#    #+#              #
#    Updated: 2024/02/15 15:18:17 by michhern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a 

SRC= ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
ft_strrchr.c ft_tolower.c ft_toupper.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_substr.c \
ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \

SRC_B=  ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \

OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDE = libft.h

LIB = ar -rcs #Comando para generar la libreria (el .a)

RM = rm -f

%.o: %.c $(INCLUDE) Makefile
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)
	@echo "Main part compiled successfully."

all: $(NAME) #comando de ejecucion 
	@echo "Main part compiled successfully."

.bonus: $(NAME) $(OBJ_B)
	$(LIB) $(NAME) $(OBJ) $(OBJ_B)
	touch .bonus

bonus: .bonus

clean:
	$(RM) $(OBJ) $(OBJ_B) .bonus

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
