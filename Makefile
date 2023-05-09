
SRCS        :=      printf.c \
                          printf_d_i_u.c \
                          ft_putchar_fd.c \
                          printf_pf.c \
                          printf_x_X.c \
                          printf_p.c
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
OBJS := $(SRCS:%.c=%.o)
#BSRCS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstsize.c ft_lstnew.c
#BOBJS = $(BSRCS:%.c=%.o)

$(NAME): $(OBJS)
	ar -crs $(NAME) $(OBJS)
#bonus: $(BOBJS) $(OBJS)
#	ar -crs $(NAME) $(OBJS) $(BOBJS)
all: $(NAME)
clean:
	rm -f $(OBJS) $(BOBJS)
fclean: clean
	rm -f $(NAME)
re: fclean $(NAME)
.PHONY: bonus all clean fclean re
