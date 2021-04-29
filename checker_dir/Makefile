# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarot <abarot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/20 17:58:02 by abarot            #+#    #+#              #
#    Updated: 2021/04/29 15:01:03 by abarot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	../checker

SRCS	=	srcs/checker.c \
			../shared_srcs/init_and_check.c \
			../shared_srcs/operations.c 

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
			rm srcs/checker.o

fclean	:	clean
			rm $(NAME)

re		:	fclean 
			make all