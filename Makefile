# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarot <abarot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/20 17:58:02 by abarot            #+#    #+#              #
#    Updated: 2021/03/12 16:32:37 by abarot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	main.c

OBJS	=	$(SRCS:.c=.o)

CC		=	clang

CFLAGS	+=	-Wall -Wextra -Werror 

all		:	
			make -C libft
			make $(NAME)

$(NAME) :	$(OBJS)
			clang $(CFLAGS) $(OBJS) -o $@ -I.

clean	:	
			make -C libft clean && rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean 
			make all