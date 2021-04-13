#include "push_swap.h"

int	ft_is_smallest(int value, t_algo_value algo_value)
{
	if (value > A_SONE || value > A_STWO ||
		value > A_MINSORT)
		return (0);
	return (1);
}

int get_median(t_stack *sorted)
{
	int i;

	i = 0;
	while (i < (sorted->array_size / 2))
		i++;
	return (sorted->array[i]);
}

void	ft_check_algo(t_stack *ast, t_stack *bst)
{
	t_algo_value algo_value;
	t_stack	*tmp;

	if (!(tmp = ft_calloc(1, sizeof(t_stack))) || 
		!(tmp->array = ft_calloc(ast->array_size + 1, sizeof(int))))
		return ;
	tmp->array_size = ast->array_size;
	ft_memcpy(tmp->array, ast->array, sizeof(int) * ast->array_size);
	A_SONE = simplest_sort_algo_1(tmp, bst, FALSE);
	ft_memcpy(tmp->array, ast->array, sizeof(int) * ast->array_size);
	A_STWO = simplest_sort_algo_2(tmp, bst, FALSE);
	ft_memcpy(tmp->array, ast->array, sizeof(int) * ast->array_size);
	A_MINSORT = min_sort(tmp, bst, FALSE);
	ft_clear_stack(tmp);
	if (ft_is_smallest(A_SONE, algo_value))
		simplest_sort_algo_1(ast,bst, TRUE);
	else if (ft_is_smallest(A_STWO, algo_value))
		simplest_sort_algo_2(ast,bst, TRUE);
	else
		min_sort(ast, bst, TRUE);
}

void	ft_check_sorting_algo(t_stack *ast, t_stack *bst)
{
	if (ast->array_size == 2)
	{
		ft_st_swap(ast);
		ft_putendl_fd("sa", STDOUT_FILENO);
		return ;
	}
	else if (ft_isreversed(ast))
	{
		sort_reversed(ast, bst);
		return ;
	}
	else
		ft_check_algo(ast, bst);
}

int main(int ac, char **av)
{
	t_stack *ast;
	t_stack *bst;

	if (ac < 2 || !(ast = ft_check_arg(&av[1])) || 
		!(bst = ft_init_bstack(ast->array_size)))
	{
		ft_putendl_fd(ERROR_MESSAGE, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (!ft_issorted(ast))
	{
		ft_check_sorting_algo(ast, bst);
	}
	ft_display_stack(ast, bst);
	ft_clear_stack(ast);
	ft_clear_stack(bst);
	return (EXIT_SUCCESS);
}
