NAME ?= libftprintf.a
CC ?= gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_SRC_FILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

LIB_SRC = $(addprefix libft/, $(LIBFT_SRC_FILES))
SRCS = 	ft_printf.c \
		printf_d_i_u.c \
		printf_p.c \
		printf_x_X.c \
		printf_pf.c
		$(LIB_SRC)

OBJS = ${SRCS:.c=.o}

BONUS_OBJS = $(BONUS:.c=.o)

all: ${NAME}

${NAME}: ${OBJS}
	make -C ./libft
	ar rcs ${NAME} ${OBJS}

bonus:	${OBJS} ${BONUS_OBJS}
	ar rcs ${NAME} ${OBJS} ${BONUS_OBJS}

%.o: %.c
	${CC} ${CFLAGS} -o ${@} -c ${@:.o=.c}

re: fclean all

fclean: clean
	rm -f ${NAME}

clean:
	rm -f ${OBJS} ${BONUS_OBJS}

.PHONY: clean fclean re all