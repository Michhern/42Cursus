# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: michhern <michhern@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 16:46:19 by michhern          #+#    #+#              #
#    Updated: 2024/03/20 17:40:27 by michhern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

DEL_LINE =		\033[2K
ITALIC =		\033[3m
BOLD =			\033[1m
DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
DARK_GREEN =	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m

SRCS = ft_putchar.c ft_putnbr.c ft_putnbr_len.c ft_strlen.c \
ft_putstr.c ft_hexalen.c ft_hexadecimal.c ft_printf.c ft_nbrunsig.c \

INCLUDE = printf.h 

CC = gcc
RM = rm -f 
LIB = ar rcs
CFLAGS = -Wall -Wextra -Werror

%.o: %.c ${INCLUDE}
	@${CC} ${CFLAGS} -c $< -o $@
	@echo "${BLUE} ◎ $(BROWN)Compiling ${MAGENTA}→   $(CYAN)$< $(DEF_COLOR)"

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	@${LIB} ${NAME} ${OBJS}
	@echo "\n$(GREEN) Created $(NAME) ✓ $(DEF_COLOR)\n"

clean:
	@${RM} ${OBJS}
	@echo "\n${BLUE} ◎ $(RED)All objects cleaned successfully ${BLUE} ◎ $(DEF_COLOR)\n"

fclean:
	@${RM} ${OBJS}
	@${RM} ${NAME}
	@echo "\n${BLUE} ◎ $(RED)All objects and executable cleaned successfully ${BLUE} ◎ $(DEF_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re
