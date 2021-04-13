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
# define V_MEDIAN		algo_value.median
# define A_SONE			algo_value.s_one
# define A_STWO			algo_value.s_two
# define A_QSORT		algo_value.quick_sort
# define A_MINSORT		algo_value.min_sorting
# define FALSE			0
# define TRUE			1

typedef struct	s_algo_value
{
	int			s_one;
	int			s_two;
	int			min_sorting;
}				t_algo_value;

int		min_sort(t_stack *ast, t_stack *bst, int dspl);
int		ft_isreversed(t_stack *ast);
void	sort_reversed(t_stack *ast, t_stack *bst);
int		simplest_sort_algo_1(t_stack *ast, t_stack *bst, int dspl);
int		simplest_sort_algo_2(t_stack *ast, t_stack *bst, int dspl);

#endif