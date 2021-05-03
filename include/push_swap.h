/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:28:32 by abarot            #+#    #+#             */
/*   Updated: 2021/05/03 12:36:12 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "checker.h"

# define UP				0
# define DOWN			1

enum					e_special_cases
{
	NO_SPECIAL,
	INTRO_MAX,
	INTRO_MIN,
	INTRO_NB_FIRST,
	INTRO_NB_LAST,
	REVERSED,
};

typedef struct			s_algos
{
	char				*s_one_solution;
	char				*s_two_solution;
	char				*selec_solution;
}						t_algos;

void					check_algo_small(t_stack *ast, t_stack *bst);
int						is_special_case(t_stack *ast);
char					*do_special_case(t_stack *ast, t_stack *bst,
						int special);
char					*sort_reversed(char *res, t_stack *ast, t_stack *bst);
char					*simplest_sort_algo_1(t_stack *ast, t_stack *bst);
char					*simplest_sort_algo_2(t_stack *ast, t_stack *bst);
char					*simplest_sort_algo_3(t_stack *ast, t_stack *bst);
char					*selection_sort(t_stack *ast, t_stack *bst);
char					*selection_sort_chunked(t_stack *ast, t_stack *bst,
						int chunk_len);
int						*get_sorted_chunks(t_stack ast);
int						is_sorted_if_rotated(t_stack ast);
int						ft_search_in_stack(t_stack ast, int nb);
int						ft_get_min(t_stack ast);
int						ft_get_max(t_stack ast);
char					*push_min(t_stack *ast, t_stack *bst, char *res);
char					*push_max(t_stack *ast, t_stack *bst, char *res);
char					*push_min(t_stack *ast, t_stack *bst, char *res);
char					*ft_do_action_sta(char *res, int (*action)(t_stack *),
											t_stack *ast, t_stack *bst);
char					*ft_do_action_stb(char *res, int (*action)(t_stack *),
											t_stack *ast, t_stack *bst);
char					*ft_do_action_both(char *res, int (*action)(t_stack *),
											t_stack *ast, t_stack *bst);
char					*ft_do_pusha(char *res, t_stack *ast, t_stack *bst);
char					*ft_do_pushb(char *res, t_stack *ast, t_stack *bst);

#endif
