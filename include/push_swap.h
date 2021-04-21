#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "checker.h"

# define V_FIRST_A		ast->array[0]
# define V_SECOND_A		ast->array[1]
# define V_LAST_A		ast->array[ast->array_size - 1]
# define V_SECLAST_A	ast->array[ast->array_size - 2]
# define V_FIRST_B		bst->array[0]
# define V_SECOND_B		bst->array[1]
# define V_LAST_B		bst->array[bst->array_size - 1]
# define V_SECLAST_B	bst->array[bst->array_size - 2]
# define C_SA			(V_FIRST_A > V_SECOND_A)
# define C_SB			(V_FIRST_B < V_SECOND_B)
# define C_RA			((V_FIRST_A > V_LAST_A && V_FIRST_A > V_SECLAST_A))
# define C_RB			((V_FIRST_B < V_LAST_B && V_FIRST_B < V_SECLAST_B))
# define C_RRA			(V_FIRST_A > V_LAST_A)
# define C_RRB			(V_FIRST_B < V_LAST_B)
# define C_DOUBLE		((C_SA && C_SB) || (C_RA && C_RB) || (C_RRA && C_RRB))
# define S_SONE			algos.s_one_solution
# define S_STWO			algos.s_two_solution
# define S_SELECSORT	algos.selec_solution
# define FALSE			0
# define TRUE			1
# define UP				0
# define DOWN			1

typedef struct	s_algos
{
	char		*s_one_solution;
	char		*s_two_solution;
	char		*selec_solution;
}				t_algos;

int		ft_isreversed(t_stack *ast);
void	sort_reversed(t_stack *ast, t_stack *bst);
char	*simplest_sort_algo_1(t_stack *ast, t_stack *bst);
char	*simplest_sort_algo_2(t_stack *ast, t_stack *bst);
char	*selection_sort(t_stack *ast, t_stack *bst);
int		ft_search_in_stack(t_stack ast, int nb);
int		ft_get_min(t_stack ast);
int		ft_search_in_stack(t_stack ast, int nb);
char	*push_min(t_stack *ast, t_stack *bst, char *res);
char	*ft_do_action_sta(char *res, int (*action)(t_stack *), t_stack *stack);
char	*ft_do_action_stb(char *res, int (*action)(t_stack *), t_stack *stack);
char	*ft_do_pusha(char *res, t_stack *ast, t_stack *bst);
char	*ft_do_pushb(char *res, t_stack *ast, t_stack *bst);
char	*selection_sort_chunked(t_stack *ast, t_stack *bst);

#endif