# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarot <abarot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/20 17:58:02 by abarot            #+#    #+#              #
#    Updated: 2021/03/15 12:13:24 by abarot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	../push_swap

SRCS	=	srcs/main.c \
			../srcs/init_and_check.c \
			../srcs/operations.c \

OBJS	=	$(SRCS:.c=.o)

CC		=	clang

INCLUDE	=	../include

CFLAGS	+=	-Wall -Wextra -Werror

%.o : %.c
		clang $(CFLAGS) -c $< -o $@ -I$(INCLUDE)

all		:	
			make -C ../libft
			make $(NAME)

$(NAME) :	$(OBJS)
			clang $(CFLAGS) $(OBJS) -o $@ -L../libft -lft -I$(INCLUDE) 
			chmod 755 $@ 

clean	:	
			make -C ../libft clean && rm $(OBJS)

fclean	:	clean
			rm $(NAME)

re		:	fclean 
			make all