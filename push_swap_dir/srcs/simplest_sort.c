#include "push_swap.h"

int	simplest_sort_algo_1(t_stack *ast, t_stack *bst, int dspl)
{
	int count;
	int dspl_val;
	char **str_list;

	str_list = ft_split("sa;sb;ss;pa;pb;ra;rb;rr;rra;rrb;rrr", ';');
	count = 0;
	while (bst->array_size || !ft_issorted(ast))
	{
		count++;
		if (C_SA)
			dspl_val = ft_st_swap(ast);
		else if (C_RA)
			dspl_val = ft_st_rot(ast);
		else if (C_RRA)
			dspl_val = ft_st_revrot(ast);
		else if (!ft_issorted(ast))
			dspl_val = ft_st_push(bst, ast) + 1;
		else if (bst->array_size)
			dspl_val = ft_st_push(ast, bst);
		if (dspl == TRUE)
			ft_putendl_fd(str_list[dspl_val], STDOUT_FILENO);
	}
	ft_clear_map(str_list);
	return (count);
}

int	simplest_sort_algo_2(t_stack *ast, t_stack *bst, int dspl)
{
	int count;
	int dspl_val;
	char **str_list;

	str_list = ft_split("sa;sb;ss;pa;pb;ra;rb;rr;rra;rrb;rrr", ';');
	count = 0;
	while (bst->array_size || !ft_issorted(ast))
	{
		count++;
		if (C_RA)
			dspl_val = ft_st_rot(ast);
		else if (C_RRA)
			dspl_val = ft_st_revrot(ast);
		else if (C_SA)
			dspl_val = ft_st_swap(ast);
		else if (!ft_issorted(ast))
			dspl_val = ft_st_push(bst, ast) + 1;
		else if (bst->array_size)
			dspl_val = ft_st_push(ast, bst);
		if (dspl == TRUE)
			ft_putendl_fd(str_list[dspl_val], STDOUT_FILENO);
	}
	ft_clear_map(str_list);
	return (count);
}
