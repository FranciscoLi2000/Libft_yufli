# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/14 21:41:16 by yufli             #+#    #+#              #
#    Updated: 2025/11/14 22:38:15 by yufli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft_add.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I ../includes
AR			= ar rcs

SRC_DIR		= .
SRC			= $(wildcard $(SRC_DIR)/*.c)

OBJ_DIR		= obj
OBJ			= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

DEPS		= $(OBJ:.o=.d)

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "[ADDL] Created $(NAME)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -MMD -c $< -o $@
	@echo "[ADDL] Compiled $<"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "[ADDL] clean done"

fclean: clean
	@rm -f $(NAME)
	@echo "[ADDL] fclean done"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
