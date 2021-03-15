
#include "../include/checker.h"

void	ft_clear_stack(t_stack *st)
{
	free(st->array);
	free(st);
}

int	ft_isordered(t_stack *astack)
{
	int tmp;
	int i;

	i = 1;
	tmp = astack->array[0];
	while (i < astack->array_size)
	{
		if (tmp > astack->array[i])
			return (0);
		tmp = astack->array[i];
		i++;
	}
	return (1);
}

t_stack	*ft_check_arg(char **arg)
{
	int i;
	t_stack *astack;

	i = 0;
	if (!(astack = ft_calloc(1, sizeof(t_stack))) ||
		!(astack->array = ft_calloc(ft_count_line(arg), sizeof(int))))
		return (NULL);
	while (arg[i])
	{
		if (!ft_isft_str(arg[i], ft_isdigit) ||
			(astack->array[i] = ft_atoi(arg[i])) != ft_atol(arg[i]))
			return (NULL);
		i++;
	}
	astack->array_size = i;
	return (astack);
}

void ft_display_stack(t_stack *ast, t_stack *bst)
{
	printf("\nastack :\n");
	for (int i = 0; i < ast->array_size; i++)
	{
		printf("%d ", ast->array[i]);
	}
	printf("\nbstack :\n");
	for (int i = 0; i < bst->array_size; i++)
	{
		printf("%d ", bst->array[i]);
	}
}

t_stack *ft_init_bstack()
{
	t_stack *bstack;

	if (!(bstack = ft_calloc(1, sizeof(t_stack))) ||
		!(bstack->array = ft_calloc(1, sizeof(int))))
		return (NULL);
	bstack->array_size = 0;
	return (bstack);
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

	if (ac < 2 || !(ast = ft_check_arg(&av[1])) || !(bst = ft_init_bstack()))
	{
		ft_putendl_fd(ERROR_MESSAGE, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	ft_read_operation(&ast, &bst);
	if (!bst->array_size && ft_isordered(ast))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
	{
		ft_putendl_fd("KO", STDOUT_FILENO);
	}
	ft_clear_stack(ast);
	ft_clear_stack(bst);
	return (EXIT_SUCCESS);
}
