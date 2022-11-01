# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 02:17:36 by mmatsuo           #+#    #+#              #
#    Updated: 2022/11/01 19:19:54 by mmatsuo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-I include

LIST_SRCS	=	src/list/ft_lstadd_back.c	\
				src/list/ft_lstadd_front.c	\
				src/list/ft_lstclear.c		\
				src/list/ft_lstdelone.c		\
				src/list/ft_lstfirst.c		\
				src/list/ft_lstiter.c		\
				src/list/ft_lstlast.c		\
				src/list/ft_lstmap.c		\
				src/list/ft_lstnew.c		\
				src/list/ft_lstsize.c

OP_SRCS		=	src/op/push.c				\
				src/op/reverse_rotate.c		\
				src/op/rotate.c				\
				src/op/swap.c

SORT_SRCS	=	src/check_func.c				\
				src/coordinate_compression.c	\
				src/error.c						\
				src/free_func.c					\
				src/input_to_stack.c			\
				src/main.c						\
				src/radix_sort.c				\
				src/sort_stack.c				\
				src/sort_utils.c				\
				src/words_count.c

SRCS		=	$(LIST_SRCS) $(OP_SRCS) $(SORT_SRCS)
OBJS		=	$(SRCS:%.c=$(OBJDIR)/%.o)
LIBFTDIR	=	libft
OBJDIR		=	objs

all:	$(NAME)

$(NAME):	$(OBJS)
			@make -C $(LIBFTDIR)
			$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -lft -o $(NAME)

$(OBJDIR)/%.o:%.c
			@mkdir -p $(@D)
			$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE)

clean:
		rm -rf $(OBJDIR)
		make fclean -C libft

fclean:	clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re
