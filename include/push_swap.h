/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:28:32 by abarot            #+#    #+#             */
/*   Updated: 2021/04/29 12:48:48 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "checker.h"

# define FALSE			0
# define TRUE			1
# define UP				0
# define DOWN			1

typedef struct			s_algos
{
	char				*s_one_solution;
	char				*s_two_solution;
	char				*selec_solution;
}						t_algos;

int						ft_isreversed(t_stack *ast);
void					sort_reversed(t_stack *ast, t_stack *bst);
char					*simplest_sort_algo_1(t_stack *ast, t_stack *bst);
char					*simplest_sort_algo_2(t_stack *ast, t_stack *bst);
char					*selection_sort(t_stack *ast, t_stack *bst);
int						ft_search_in_stack(t_stack ast, int nb);
int						ft_get_min(t_stack ast);
int						ft_search_in_stack(t_stack ast, int nb);
char					*push_min(t_stack *ast, t_stack *bst, char *res);
char					*ft_do_action_sta(char *res, int (*action)(t_stack *),
											t_stack *stack);
char					*ft_do_action_stb(char *res, int (*action)(t_stack *),
											t_stack *stack);
char					*ft_do_action_both(char *res, int (*action)(t_stack *),
											t_stack *ast, t_stack *bst);
char					*ft_do_pusha(char *res, t_stack *ast, t_stack *bst);
char					*ft_do_pushb(char *res, t_stack *ast, t_stack *bst);
char					*selection_sort_chunked(t_stack *ast, t_stack *bst);

#endif
