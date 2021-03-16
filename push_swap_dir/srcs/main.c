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

void	first_sort_algo(t_stack **ast, t_stack **bst)
{
	while ((*bst)->array_size || !ft_issorted(*ast))
	{
		V_MEDIAN = (*ast)->array[(*ast)->array_size / 2];
		V_FIRST = (*ast)->array[0];
		V_SECOND = (*ast)->array[1];
		V_LAST = (*ast)->array[(*ast)->array_size - 1];
		if (V_FIRST > V_SECOND && V_FIRST > V_MEDIAN)
		{
			ft_putendl_fd("ra", STDOUT_FILENO);
			ft_st_rot(*ast);
		}
		else if (V_LAST < V_FIRST && V_LAST < V_SECOND)
		{
			ft_putendl_fd("rra", STDOUT_FILENO);
			ft_st_revrot(*ast);
		}
		else if (V_FIRST > V_SECOND || V_SECOND > V_LAST)
		{
			ft_putendl_fd("sa", STDOUT_FILENO);
			ft_st_swap(*ast);
		}
		else if (!ft_issorted(*ast))
		{
			ft_putendl_fd("pb", STDOUT_FILENO);
			ft_st_push(bst, ast);
		}
		else if ((*bst)->array_size)
		{
			ft_putendl_fd("pa", STDOUT_FILENO);
			ft_st_push(ast, bst);
		}
	}
}

void	ft_rearrange_stack(t_stack **ast, t_stack **bst)
{
	if (ft_isreversed(*ast))
		sort_reversed(ast, bst);
	else
		first_sort_algo(ast,bst);
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
	ft_rearrange_stack(&ast, &bst);
	ft_clear_stack(ast);
	ft_clear_stack(bst);
	return (EXIT_SUCCESS);
}
