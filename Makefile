CC		= cc
CFLAGS		= -Wall -Wextra -Werror

INCLUDE		= -I libft.h

SRC		= ft_libc/ft_atoi.c ft_libc/ft_isalnum.c ft_libc/ft_isdigit.c \
		ft_libc/ft_memcmp.c ft_libc/ft_memset.c ft_libc/ft_strlcat.c \
		ft_libc/ft_strncmp.c ft_libc/ft_tolower.c ft_libc/ft_bzero.c \
		ft_libc/ft_isalpha.c ft_libc/ft_isprint.c ft_libc/ft_memcpy.c \
		ft_libc/ft_strchr.c ft_libc/ft_strlcpy.c ft_libc/ft_strnstr.c \
		ft_libc/ft_toupper.c ft_libc/ft_calloc.c ft_libc/ft_isascii.c \
		ft_libc/ft_memchr.c ft_libc/ft_memmove.c ft_libc/ft_strdup.c \
		ft_libc/ft_strlen.c ft_libc/ft_strrchr.c \
		additional/ft_itoa.c additional/ft_putendl_fd.c additional/ft_putstr_fd.c \
		additional/ft_striteri.c additional/ft_strmapi.c additional/ft_substr.c \
		additional/ft_putchar_fd.c additional/ft_putnbr_fd.c additional/ft_split.c \
		additional/ft_strjoin.c additional/ft_strtrim.c
SRC_BONUS	= bonus/ft_lstadd_back_bonus.c bonus/ft_lstdelone_bonus.c bonus/ft_lstmap_bonus.c \
		bonus/ft_lstadd_front_bonus.c bonus/ft_lstiter_bonus.c bonus/ft_lstnew_bonus.c \
		bonus/ft_lstclear_bonus.c bonus/ft_lstlast_bonus.c bonus/ft_lstsize_bonus.c

OBJ		= $(SRC:.c=.o)
OBJ_BONUS	= $(SRC_BONUS:.c=.o)

NAME	= libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
