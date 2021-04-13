# include "push_swap.h"

int		ft_get_min(t_stack ast)
{
	int min;
	int i;

	i = 1;
	min = ast.array[0];
	while (i < ast.array_size)
	{
		if (min > ast.array[i])
			min = ast.array[i];
		i++;
	}
	return (min);
}

int	ft_search_in_stack(t_stack ast, int nb)
{
	int i;

	i = 0;
	while (i < ast.array_size)
	{
		if (ast.array[i] == nb)
			return (i);
		i++;
	}
	return (0);
}

int	min_sort(t_stack *ast, t_stack *bst, int dspl)
{
	int count;
	int min;

	count = 0;
	while (ast->array_size != 1)
	{
		min = ft_get_min(*ast);
		if (ft_search_in_stack(*ast, min) < (ast->array_size) / 2)
		{
			while (ast->array[0] != min)
			{
				count++;
				ft_st_rot(ast);
				if (dspl == TRUE)
					ft_putendl_fd("ra", STDOUT_FILENO);
			}
		}
		else
		{
			while (ast->array[0] != min)
			{
				count++;
				ft_st_revrot(ast);
				if (dspl == TRUE)
					ft_putendl_fd("rra", STDOUT_FILENO);
			}
		}
		ft_st_push(bst, ast);
		if (dspl == TRUE)
			ft_putendl_fd("pb", STDOUT_FILENO);
		count++;
	}
	while (bst->array_size)
	{
		ft_st_push(ast, bst);
		if (dspl == TRUE)
			ft_putendl_fd("pa", STDOUT_FILENO);
		count++;
	}
	return (count);
}