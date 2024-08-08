# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: michhern <michhern@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 13:25:02 by michhern          #+#    #+#              #
#    Updated: 2024/08/08 13:55:22 by michhern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Standard
NAME 			= libft.a

# Directories
INC 			= inc/
SRC_DIR 		= src/
OBJ_DIR			= obj/

# Compiladores y Flags
CC				= gcc
CFLAGS 			= -Wall -Wextra -Werror -I
RM				= rm -rf
AR				= ar -rcs

# Source Files
FTTO_DIR		= $(SRC_DIR)ft_to/ft_atoi.c \
							ft_to/ft_itoa.c \
							ft_to/ft_tolower.c \
							ft_to/ft_toupper.c \

FTIS_DIR		= $(SRC_DIR)ft_is/ft_isalnum.c \
							ft_is/ft_isalpha.c \
							ft_is/ft_isascii.c \
							ft_is/ft_isdigit.c \
							ft_is/ft_isprint.c \

FTLST_DIR		= $(SRC_DIR)ft_lst/ft_lstadd_back.c \
							ft_lst/ft_lstadd_front.c \
							ft_lst/ft_lstclear.c \
							ft_lsr/ft_lstdelone.c \
							ft_lst/ft_lstiter.c \
							ft_lst/ft_lstlast.c \
							ft_lst/ft_lstmap.c \
							ft_lst/ft_lstnew.c \
							ft_lst/ft_lstsize.c \

FTMEM_DIR		= $(SRC_DIR)ft_mem/ft_memchr.c \
							ft_mem/ft_memcmp.c \
							ft_mem/ft_memcpy.c \
							ft_mem/ft_meemmove.c \
							ft_mem/ft_memset.c \
							ft_mem/ft_bzero.c \
							ft_mem/ft_calloc.c \

FTPUT_DIR		= $(SRC_DIR)ft_put/ft_putchar_fd.c \
							ft_put/ft_putendl_fd.c \
							ft_put/ft_putnbr_fd.c \
							ft_put/ft_putstr_fd.c \

FTSTR_DIR		= $(SRC_DIR)ft_str/ft_split.c \
							ft_str/ft_strchr.c \
							ft_str/ft_strdup.c \
							ft_str/ft_striteri.c \
							ft_str/ft_strjoin.c \
							ft_str/ft_strlcat.c \
							ft_str/ft_strlcpy.c \
							ft_str/ft_strlen.c \
							ft_str/ft_strmapi.c \
							ft_str/ft_strncmp.c \
							ft_str/ft_strnstr.c \
							ft_str/ft_strrchr.c \
							ft_str/ft_strtrim.c \
							ft_str/ft_substr.c \

FTPRINTF_DIR	= $(SRC_DIR)ft_printf/ft_hexadecimal.c \
							ft_printf/ft_hexalen.c \
							ft_printf/ft_nbrunsig.c \
							ft_printf/ft_printf.c \
							ft_printf/ft_putchar.c \
							ft_printf/ft_putnbr.c \
							ft_printf/ft_putnbr_len.c \
							ft_printf/ft_putstr.c \
							ft_printf/ft_strlen.c \

GNTL_DIR		= $(SRC_DIR)get_next_line/get_next_line.c \
							get_next_line/get_next_line_utils.c \

# Concatenate all source files
SRC				= $(FTTO_DIR) $(FTIS_DIR) $(FTLST_DIR) $(FTMEM_DIR) $(FTPUT_DIR) $(FTSTR_DIR) $(FTPRINTF_DIR) $(GNTL_DIR)

# Apply the pattern substitution to each source file in SRC and 
#produce a corresponding list of object files in the OBJ_DIR
OBJ				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))


# Build rules
all: 			$(NAME)

$(NAME): 		$(OBJ)
				@$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
				@$(RM) -r $(OBJ_DIR)
				@$(RM) .cache_exists

fclean: 		clean
				@$(RM) $(NAME)

re: 			fclean all

.PHONY: 		all clean fclean re
