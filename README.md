# Libft_yufli
# This is a library created by yufli in 42Barcelona

#ifndef LIBFT_H
#define LIBFT_H

 the prototypes of all of the functions in the projects.

#endif

# Makefile

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRCS = ft_*.c \

# Object files (automatically generated from source files)
OBJS = $(SRCS:.c=.o)

# Header file
HEADER = libft.h

# Rules
all: $(NAME)

# Create the library
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Compile source files to object files
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS) $(BONUS_OBJS)

# Clean object files and the library
fclean: clean
	rm -f $(NAME)

# Re-make everything
re: fclean all

# Ensure these rules are executed even if files with the same names exist
.PHONY: all clean fclean re bonus