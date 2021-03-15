#include "push_swap.h"

void	ft_rearrange_stack(t_stack **ast, t_stack **bst)
{
	int median;
	int first_value;
	int second_value;
	int last_value;

	while ((*bst)->array_size || !ft_isordered(*ast))
	{
		median = (*ast)->array[(*ast)->array_size / 2];
		first_value = (*ast)->array[0];
		second_value = (*ast)->array[1];
		last_value = (*ast)->array[(*ast)->array_size - 1];
		if (first_value > last_value)
		{
			ft_putendl_fd("ra", STDOUT_FILENO);
			ft_st_rot(*ast);
		}
		else if (last_value < first_value)
		{
			ft_putendl_fd("rra", STDOUT_FILENO);
			ft_st_revrot(*ast);
		}
		else if (first_value > second_value || second_value > last_value)
		{
			ft_putendl_fd("sa", STDOUT_FILENO);
			ft_st_swap(*ast);
		}
		else if (!ft_isordered(*ast))
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
