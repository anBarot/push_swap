# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarot <abarot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/20 17:58:02 by abarot            #+#    #+#              #
#    Updated: 2021/03/15 19:28:21 by abarot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG_ONE	=	checker

PROG_TWO	=	push_swap

PROG_ONE_DIR	=	checker_dir

PROG_TWO_DIR	=	push_swap_dir

LIB_DIR		=	libft

all		:	
			make -C $(PROG_ONE_DIR)
			make -C $(PROG_TWO_DIR)

checker	:	
			make -C $(PROG_ONE_DIR)

push_swap	:
				make -C $(PROG_TWO_DIR)

test	:
			test_dir/test_generator.sh

clean	:	
			make -C $(LIB_DIR) clean
			make -C $(PROG_ONE_DIR) clean 

fclean	:	clean
			rm $(PROG_ONE) $(PROG_TWO)

re		:	fclean
			make all