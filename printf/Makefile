# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 02:15:54 by mmatsuo           #+#    #+#              #
#    Updated: 2022/11/01 02:15:56 by mmatsuo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c \
				ft_put_str.c \
				ft_put_ptr.c

OBJS = $(SRCS:.c=.o)

CC = CC

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean: clean
			$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re