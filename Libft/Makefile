# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/14 21:41:16 by yufli             #+#    #+#              #
#    Updated: 2025/11/16 07:22:18 by yufli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I ../includes
AR		= ar rcs

SRC		= $(wildcard LIBC_functions/*.c) $(wildcard Additional/*.c)

OBJ_DIR	= obj
OBJ		= $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))

DEPS	= $(OBJ:.o=.d)

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "[libft] $(NAME) created"

# Pattern rule:
# target: obj/LIBC_functions/ft_atoi.o
# prerequisite: LIBC_functions/ft_atoi.c

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -MMD -c $< -o $@
	@echo "[libft] Compiled $<"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "[libft] clean done"

fclean: clean
	@rm -f $(NAME)
	@echo "[libft] fclean done"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
