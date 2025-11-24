NAME		:= libft.a

CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror

AR		:= ar rcs
RM		:= rm -f

# 源文件
SRCS		:= ft_putchar.c ft_strlen.c ft_strdup.c

# 根据 SRCS 生成对应 .o
OBJS		:= $(SRCS:.c=.o)

# ================================================== #
#                      Rules                         #
# ================================================== #

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# 通用 .c => .o 规则
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
