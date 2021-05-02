# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarot <abarot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/20 17:58:02 by abarot            #+#    #+#              #
#    Updated: 2021/05/02 14:59:45 by abarot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	../push_swap

SRCS	=	srcs/push_swap.c \
			srcs/get_min_max.c \
			srcs/check_algo_small.c \
			srcs/simplest_sort.c \
			srcs/selection_sort.c \
			srcs/selection_sort_chunked.c \
			srcs/do_action.c \
			srcs/get_sorted_chunks.c

SHARED_SRCS	=	../shared_srcs/init_and_check.c \
				../shared_srcs/operations.c \
				../shared_srcs/ft_display_stack.c

OBJS	=	$(SRCS:.c=.o)

SHARED_OBJS	=	$(SHARED_SRCS:.c=.o)

CC		=	clang

INCLUDE	=	../include

CFLAGS	+=	-g -Wall -Wextra -Werror

%.o : %.c
		clang $(CFLAGS) -c $< -o $@ -I$(INCLUDE)

all		:	
			make -C ../libft
			make $(NAME)

$(NAME) :	$(OBJS) $(SHARED_OBJS)
			clang $(CFLAGS) $(OBJS) $(SHARED_OBJS) -o $@ -L../libft -lft -I$(INCLUDE) 
			chmod 755 $@ 

clean	:	
			rm	$(OBJS)

fclean	:	clean
			rm $(NAME)

re		:	fclean 
			make all