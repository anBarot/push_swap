#include "push_swap.h"

int		ft_isreversed(t_stack *ast)
{
	int i;
	int tmp;

	i = 1;
	tmp = ast->array[0];
	while (i < ast->array_size)
	{
		if (tmp < ast->array[i])
			return (0);
		tmp = ast->array[i];
		i++;
	}
	return (1);
}

void	sort_reversed(t_stack **ast, t_stack **bst)
{
	while ((*ast)->array_size != 3)
	{
		ft_putendl_fd("rra", STDOUT_FILENO);
		ft_st_revrot(*ast);
		ft_putendl_fd("pb", STDOUT_FILENO);
		ft_st_push(bst, ast);
	}
	ft_putendl_fd("ra", STDOUT_FILENO);
	ft_st_rot(*ast);
	ft_putendl_fd("sa", STDOUT_FILENO);
	ft_st_swap(*ast);
	while ((*bst)->array_size)
	{
		ft_putendl_fd("pa", STDOUT_FILENO);
		ft_st_push(ast, bst);
	}
}

int	simplest_sort_algo_1(t_stack **ast, t_stack **bst, int dspl)
{
	int count;
	int dspl_val;
	char **str_list;

	str_list = ft_split("sa;sb;ss;pa;pb;ra;rb;rr;rra;rrb;rrr", ';');
	count = 0;
	while ((*bst)->array_size || !ft_issorted(*ast))
	{
		count++;
		if (V_FIRST > V_SECOND)
			dspl_val = ft_st_swap(*ast);
		else if (V_FIRST > V_LAST)
			dspl_val = ft_st_rot(*ast);
		else if (V_LAST < V_FIRST)
			dspl_val = ft_st_revrot(*ast);
		else if (!ft_issorted(*ast))
			dspl_val = ft_st_push(bst, ast) + 1;
		else if ((*bst)->array_size)
			dspl_val = ft_st_push(ast, bst);
		if (dspl == TRUE)
			ft_putendl_fd(str_list[dspl_val], STDOUT_FILENO);
	}
	ft_clear_map(str_list);
	return (count);
}

int	simplest_sort_algo_2(t_stack **ast, t_stack **bst, int dspl)
{
	int count;
	int dspl_val;
	char **str_list;

	str_list = ft_split("sa;sb;ss;pa;pb;ra;rb;rr;rra;rrb;rrr", ';');
	count = 0;
	while ((*bst)->array_size || !ft_issorted(*ast))
	{
		count++;
		if (V_LAST < V_FIRST)
			dspl_val = ft_st_revrot(*ast);
		else if (V_FIRST > V_LAST)
			dspl_val = ft_st_rot(*ast);
		else if (V_FIRST > V_SECOND)
			dspl_val = ft_st_swap(*ast);
		else if (!ft_issorted(*ast))
			dspl_val = ft_st_push(bst, ast) + 1;
		else if ((*bst)->array_size)
			dspl_val = ft_st_push(ast, bst);
		if (dspl == TRUE)
			ft_putendl_fd(str_list[dspl_val], STDOUT_FILENO);
	}
	ft_clear_map(str_list);
	return (count);
}

int	simplest_sort_algo_3(t_stack **ast, t_stack **bst, int dspl)
{
	int count;
	int dspl_val;
	char **str_list;

	str_list = ft_split("sa;sb;ss;pa;pb;ra;rb;rr;rra;rrb;rrr", ';');
	count = 0;
	while ((*bst)->array_size || !ft_issorted(*ast))
	{
		count++;
		if (V_FIRST > V_LAST)
			dspl_val = ft_st_rot(*ast);
		else if (V_LAST < V_FIRST)
			dspl_val = ft_st_revrot(*ast);
		else if (V_FIRST > V_SECOND)
			dspl_val = ft_st_swap(*ast);
		else if (!ft_issorted(*ast))
			dspl_val = ft_st_push(bst, ast) + 1;
		else if ((*bst)->array_size)
			dspl_val = ft_st_push(ast, bst);
		if (dspl == TRUE)
			ft_putendl_fd(str_list[dspl_val], STDOUT_FILENO);
	}
	ft_clear_map(str_list);
	return (count);
}

void	ft_rearrange_stack(t_stack **ast, t_stack **bst)
{
	t_algo_value algo_value;
	t_stack	*tmp;

	if ((*ast)->array_size == 2)
	{
		ft_st_swap(*ast);
		ft_putendl_fd("sa", STDOUT_FILENO);
		return ;
	}
	else if (ft_isreversed(*ast))
	{
		sort_reversed(ast, bst);
		return ;
	}
	tmp = ft_calloc(1, sizeof(t_stack));
	tmp->array_size = (*ast)->array_size;
	tmp->array = ft_calloc((*ast)->array_size + 1, sizeof(int));
	ft_memcpy(tmp->array, (*ast)->array, sizeof(int) * (*ast)->array_size);
	A_SONE = simplest_sort_algo_1(&tmp,bst,FALSE);
	ft_memcpy(tmp->array, (*ast)->array, sizeof(int) * (*ast)->array_size);
	A_STWO = simplest_sort_algo_2(&tmp,bst,FALSE);
	ft_memcpy(tmp->array, (*ast)->array, sizeof(int) * (*ast)->array_size);
	A_STHREE = simplest_sort_algo_3(&tmp,bst,FALSE);
	ft_clear_stack(tmp);
	if (A_SONE <= A_STWO && A_SONE <= A_STHREE)
		simplest_sort_algo_1(ast,bst, TRUE);
	else if (A_STWO < A_SONE && A_STWO <= A_STHREE)
		simplest_sort_algo_2(ast,bst, TRUE);
	else
		simplest_sort_algo_3(ast,bst, TRUE);
}

int main(int ac, char **av)
{
	t_stack *ast;
	t_stack *bst;

	if (ac < 2 || !(ast = ft_check_arg(&av[1])) || !(bst = ft_init_bstack()))
	{
		ft_putendl_fd(ERROR_MESSAGE, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (!ft_issorted(ast))
	{
		ft_rearrange_stack(&ast, &bst);
	}
	ft_clear_stack(ast);
	ft_clear_stack(bst);
	return (EXIT_SUCCESS);
}
