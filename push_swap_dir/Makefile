# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarot <abarot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/20 17:58:02 by abarot            #+#    #+#              #
#    Updated: 2021/04/29 16:19:09 by abarot           ###   ########.fr        #
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
			../shared_srcs/init_and_check.c \
			../shared_srcs/operations.c \

OBJS	=	$(SRCS:.c=.o)

CC		=	clang

INCLUDE	=	../include

CFLAGS	+=	-g -Wall -Wextra -Werror

%.o : %.c
		clang $(CFLAGS) -c $< -o $@ -I$(INCLUDE)

all		:	
			make -C ../libft
			make $(NAME)

$(NAME) :	$(OBJS)
			clang $(CFLAGS) $(OBJS) -o $@ -L../libft -lft -I$(INCLUDE) 
			chmod 755 $@ 

clean	:	
			rm	srcs/push_swap.o \
				srcs/get_min_max.o \
				srcs/check_algo_small.o \
				srcs/simplest_sort.o \
				srcs/selection_sort.o \
				srcs/selection_sort_chunked.o \
				srcs/do_action.o

fclean	:	clean
			rm $(NAME)

re		:	fclean 
			make all