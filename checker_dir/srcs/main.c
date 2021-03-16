
#include "checker.h"

int	ft_get_operation(t_stack **astack, t_stack **bstack, char *line) 
{
	if (!(ft_strncmp(line, "sa", 3)) || !(ft_strncmp(line, "ss", 3)))
		ft_st_swap(*astack);
	if (!(ft_strncmp(line, "sb", 3)) || !(ft_strncmp(line, "ss", 3)))
		ft_st_swap(*bstack);
	if (!(ft_strncmp(line, "ra", 3)) || !(ft_strncmp(line, "rr", 3)))
		ft_st_rot(*astack);
	if (!(ft_strncmp(line, "rb", 3)) || !(ft_strncmp(line, "rr", 3)))
		ft_st_rot(*bstack);
	if (!(ft_strncmp(line, "rra", 4)) || !(ft_strncmp(line, "rrr", 4)))
		ft_st_revrot(*astack);
	if (!(ft_strncmp(line, "rrb", 4)) || !(ft_strncmp(line, "rrr", 4)))
		ft_st_revrot(*bstack);
	if (!(ft_strncmp(line, "pa", 3)))
		ft_st_push(astack, bstack);
	if (!(ft_strncmp(line, "pb", 3)))
		ft_st_push(bstack, astack);
	return (EXIT_SUCCESS);
}

void	ft_read_operation(t_stack **ast, t_stack **bst)
{
	char *line;
	int value;

	while ((value = get_next_line(STDIN_FILENO, &line)))
	{
		if (value == -1)
		{
			ft_putendl_fd(ERROR_MESSAGE, STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		ft_get_operation(ast, bst, line);
		free(line);
	}
	free(line);
}

int main(int ac, char **av)
{
	t_stack *ast;
	t_stack *bst;

	if (ac < 2 || !(bst = ft_init_bstack()) || !(ast = ft_check_arg(&av[1])))
	{
		ft_putendl_fd(ERROR_MESSAGE, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	ft_read_operation(&ast, &bst);
	if (!bst->array_size && ft_issorted(ast))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
	{
		ft_putendl_fd("KO", STDOUT_FILENO);
	}
	ft_clear_stack(ast);
	ft_clear_stack(bst);
	return (EXIT_SUCCESS);
}
