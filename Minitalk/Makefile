# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: michhern <michhern@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 12:51:29 by michhern          #+#    #+#              #
#    Updated: 2024/05/14 13:21:55 by michhern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_NAME = client
SERVER_NAME = server

CLIENT_SRCS = client.c ft_atoi.c
SERVER_SRCS = server.c

OBJS_CLIENT = $(CLIENT_SRCS:.c=.o)
OBJS_SERVER	= $(SERVER_SRCS:.c=.o)

PRINTF = printf/libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(PRINTF) $(OBJS_CLIENT)
	@echo "Complit client...!"
	@$(CC) $(CFLAGS) $(OBJS_CLIENT) $(PRINTF) -o $(CLIENT_NAME)
	@echo "\n"
	@echo " =========================== "
	@echo " client successfully created "
	@echo " =========================== "
	@echo "\n"

$(SERVER_NAME): $(PRINTF) $(OBJS_SERVER)
	@echo "Complit server...!"
	@$(CC) $(CFLAGS) $(OBJS_SERVER) $(PRINTF) -o $(SERVER_NAME)
	@echo "\n"
	@echo " =========================== "
	@echo " server successfully created "
	@echo " =========================== "
	@echo "\n"

$(PRINTF):
	@echo "Compiling libftprintf.a..."
	@make -C printf
	@echo "\n"
	@echo " ================================ "
	@echo " libftprintf.a successfully created "
	@echo "\n"

%.o: %.c Makefile minitalk.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_CLIENT) $(OBJS_SERVER)
	@make -c printf clean
	@echo " ====================== "
	@echo " All .o files removed..."
	@echo " ====================== "
	@echo "\n"

fclean: clean
	@rm -rf $(CLIENT_NAME) $(SERVER_NAME)
	@make -c printf clean
	@echo " ====================== "
	@echo " All files removed...   "
	@echo " ====================== "
	@echo "\n"

re: fclean all

.PHONY: all bonus clean fclean re