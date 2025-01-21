# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: michhern <michhern@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 12:51:29 by michhern          #+#    #+#              #
#    Updated: 2024/08/27 12:19:29 by michhern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_NAME = client
SERVER_NAME = server

CLIENT_SRCS = client.c lib.c util.c
SERVER_SRCS = server.c lib.c util.c

OBJS_CLIENT = $(CLIENT_SRCS:.c=.o)
OBJS_SERVER	= $(SERVER_SRCS:.c=.o)

CC = gcc
INCLUDES = -I minitalk.h
CFLAGS = -Wall -Wextra -Werror

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(OBJS_CLIENT)
	@echo "Complit client...!"
	@$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) -o $(CLIENT_NAME)
	@echo "\n"
	@echo " =========================== "
	@echo " client successfully created "
	@echo " =========================== "
	@echo "\n"

$(SERVER_NAME): $(OBJS_SERVER)
	@echo "Complit server...!"
	@$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(SERVER_NAME)
	@echo "\n"
	@echo " =========================== "
	@echo " server successfully created "
	@echo " =========================== "
	@echo "\n"

%.o: %.c Makefile minitalk.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_CLIENT) $(DEP_C) $(OBJS_SERVER) $(DEP_S)
	@echo " ====================== "
	@echo " All .o files removed..."
	@echo " ====================== "
	@echo "\n"

fclean: clean
	@rm -rf $(CLIENT_NAME) $(SERVER_NAME)
	@echo " ====================== "
	@echo " All files removed...   "
	@echo " ====================== "
	@echo "\n"

re: fclean all

.PHONY: all clean fclean re
