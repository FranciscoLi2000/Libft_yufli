# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/14 21:41:16 by yufli             #+#    #+#              #
#    Updated: 2025/11/14 22:47:36 by yufli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft_gnl

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I ../includes

LIBS		= ../LIBC_functions/libft.a ../Additional/libft_add.a

SRC			= $(wildcard *.c)

OBJ			= $(SRC:.c=.o)

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(filter %,. $(LIBS)) 2>/dev/null || $(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "[GNL] Built $(NAME)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "[GNL] Compiled $<"

clean:
	@rm -f $(OBJ)
	@echo "[GNL] clean done"

fclean: clean
	@rm -f $(NAME)
	@echo "[GNL] fclean done"

re: fclean all

.PHONY: all clean fclean re
