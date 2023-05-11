# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egiovann <egiovann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 16:04:42 by egiovann          #+#    #+#              #
#    Updated: 2023/05/11 16:04:45 by egiovann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS        :=      printf.c \
                          printf_d_i_u.c \
                          ft_putchar_fd.c \
                          printf_pf.c \
                          printf_x_X.c \
                          printf_p.c
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
OBJS := $(SRCS:%.c=%.o)

$(NAME): $(OBJS)
	ar -crs $(NAME) $(OBJS)
all: $(NAME)
clean:
	rm -f $(OBJS) $(BOBJS)
fclean: clean
	rm -f $(NAME)
re: fclean $(NAME)
.PHONY: bonus all clean fclean re
