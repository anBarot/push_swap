/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:26:21 by abarot            #+#    #+#             */
/*   Updated: 2021/05/03 15:33:51 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# define ERROR_MESSAGE	"Error"
# define FALSE			0
# define TRUE			1

typedef struct			s_stack
{
	int					*array;
	int					array_size;
}						t_stack;

enum					e_operation
{
	SWAP_A,
	SWAP_B,
	SWAP_AB,
	PUSH_A,
	PUSH_B,
	ROT_A,
	ROT_B,
	ROT_AB,
	RROT_A,
	RROT_B,
	RROT_AB,
};

int g_debug;
int g_color;

int						ft_st_push(t_stack *fst, t_stack *sec);
int						ft_st_revrot(t_stack *stack);
int						ft_st_rot(t_stack *stack);
int						ft_st_swap(t_stack *stack);
void					ft_clear_stack(t_stack *st);
int						is_sorted(int *array, int size, int reversed);
t_stack					*ft_check_arg(char **arg);
t_stack					*ft_init_bstack(size_t size);
void					ft_display_stack(t_stack ast, t_stack bst);
void					display_header(t_stack ast, t_stack bst, char *str);
void					display_error(void);

#endif
