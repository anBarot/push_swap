# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarot <abarot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/20 17:58:02 by abarot            #+#    #+#              #
#    Updated: 2021/04/29 17:16:13 by abarot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG_ONE	=	checker

PROG_TWO	=	push_swap

LIBFT		=	libft.a

PROG_ONE_DIR	=	checker_dir

PROG_TWO_DIR	=	push_swap_dir

SRCS			=	shared_srcs/init_and_check.c \
					shared_srcs/operations.c

OBJS			=	$(SRCS:.c=.o)

LIB_DIR		=	libft

all		:	
			make -C $(PROG_ONE_DIR)
			make -C $(PROG_TWO_DIR)

checker	:	
			make -C $(PROG_ONE_DIR)

push_swap	:
				make -C $(PROG_TWO_DIR)

test	:
			echo 'Write the array values : '
			test_dir/test_script.sh > test_dir/results/test.txt
			cat test_dir/results/test.txt

test_rando	:
				echo 'Choose the array size : '
				test_dir/test_rando_script.sh > test_dir/results/test_rando.txt
				cat test_dir/results/test_rando.txt

test_ko	:	
			echo 'Choose the array size : '
			test_dir/test_ko_script.sh > test_dir/results/test_ko.txt
			echo 'result : (% of OK)'
			cat test_dir/results/test_ko.txt | grep OK | wc -l

test_mean	:	
				echo 'Choose the array size : '
				test_dir/test_mean_script.sh > test_dir/results/test_mean.txt
				awk '{ total += $$1; count++ } END { print total/count }' test_dir/results/test_mean.txt

test_all	:
				test_dir/test_all_script.sh > test_dir/results/test_all.txt

clean	:	
			make -C $(LIB_DIR) clean
			make -C $(PROG_ONE_DIR) clean 
			make -C $(PROG_TWO_DIR) clean
			rm $(OBJS)

fclean	:	clean
			rm $(PROG_ONE) $(PROG_TWO) $(LIB_DIR)/$(LIBFT)

re		:	fclean
			make all