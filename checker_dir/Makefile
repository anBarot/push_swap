# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarot <abarot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/20 17:58:02 by abarot            #+#    #+#              #
#    Updated: 2021/05/02 13:03:22 by abarot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	../checker

SRCS	=	srcs/checker.c

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
			rm $(OBJS)

fclean	:	clean
			rm $(NAME)

re		:	fclean 
			make all