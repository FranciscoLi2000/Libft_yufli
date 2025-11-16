# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/16 10:59:44 by yufli             #+#    #+#              #
#    Updated: 2025/11/16 11:15:00 by yufli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft_gnl.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I ../includes
AR		= ar rcs

LIBFT_DIR	= ../Libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRC			= get_next_line.c fill_line_buffer.c extract_line.c
OBJ			= $(SRC:.c=.o)
DEPS		= $(OBJ:.o=.d)

.SILENT:

# 默认目标：先确保 libft 可用，然后编译 libft_gnl.a
all: $(LIBFT) $(NAME)

# 如果 libft 不存在或已过期，则进入 Libft/ 执行 make
$(LIBFT):
	@echo ">>> Building libft in $(LIBFT_DIR)"
	@$(MAKE) -C $(LIBFT_DIR)

# 归档 gnl 的 .o 为静态库
$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "[GNL] $(NAME) created"

# 编译每个 .c，自动生成依赖 (.d)
%.o: %.c
	@$(CC) $(CFLAGS) -MMD -c $< -o $@
	@echo "[GNL] Compiled $<"

clean:
	@rm -f $(OBJ) $(DEPS)
	@echo "[GNL] clean done"

# fclean 同时清理 libft（如果你不想清 libft，可以改为只清自身）
fclean: clean
	@rm -f $(NAME)
	@echo "[GNL] fclean done (removed $(NAME))"
	@echo ">>> Also running 'make fclean' in $(LIBFT_DIR)"
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
