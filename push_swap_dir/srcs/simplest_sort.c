#include "push_swap.h"

char	*simplest_sort_algo_1(t_stack *ast, t_stack *bst)
{
	int dspl_val;
	char **str_list;
	char *tmp;
	char *res;

	if (!(res = ft_calloc(1, 1)))
		return (0);
	str_list = 
	ft_split("sa\n;sb\n;ss\n;pa\n;pb\n;ra\n;rb\n;rr\n;rra\n;rrb\n;rrr\n", ';');
	while (bst->array_size || !ft_issorted(ast))
	{
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
		tmp = res;
		res = ft_strjoin(res, str_list[dspl_val]);
		free(tmp);
	}
	ft_clear_map(str_list);
	return (res);
}

char	*simplest_sort_algo_2(t_stack *ast, t_stack *bst)
{
	int dspl_val;
	char **str_list;
	char *tmp;
	char *res;

	if (!(res = ft_calloc(1, 1)))
		return (0);
	str_list = 
	ft_split("sa\n;sb\n;ss\n;pa\n;pb\n;ra\n;rb\n;rr\n;rra\n;rrb\n;rrr\n", ';');
	while (bst->array_size || !ft_issorted(ast))
	{
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
		tmp = res;
		res = ft_strjoin(res, str_list[dspl_val]);
		free(tmp);
	}
	ft_clear_map(str_list);
	return (res);
}
