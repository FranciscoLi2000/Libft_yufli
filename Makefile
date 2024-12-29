# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yufli <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/29 15:16:10 by yufli             #+#    #+#              #
#    Updated: 2024/12/29 21:29:03 by yufli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS += -Wall -Wextra -Werror

NAME = $(shell pwd)

MY_SOURCES = ft_isalpha.c \
	     ft_isdigit.c \
	     ft_isalnum.c \
	     ft_isascii.c \
	     ft_isprint.c \
	     ft_strlen.c \
	     ft_memset.c \
	     ft_bzero.c \
	     ft_memcpy.c \
	     ft_memmove.c \
	     ft_strlcpy.c \
	     ft_strlcat.c \
	     ft_toupper.c \
	     ft_tolower.c \
	     ft_strchr.c \
	     ft_strrchr.c \
	     ft_strncmp.c \
	     ft_memchr.c \
	     ft_memcmp.c \
	     ft_strnstr.c \
	     ft_atoi.c \
	     ft_calloc.c \
	     ft_strdup.c \
	     ft_substr.c \
	     ft_strjoin.c \
	     ft_strtrim.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

HEADER = libft.h

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	ar rcs $(NAME) $(MY_OBJECTS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MY_OBJECTS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

