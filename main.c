
#include "push_swap.h"

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

void	test_stack(t_stack *astack)
{
	int i = 0;
	while (i < astack->array_size)
	{
		printf("\nstack %d: %d\n", i, astack->array[i]);
		i++;
	}
}

void ft_display_stack(t_stack *st)
{
	for (int i = 0; i < st->array_size; i++)
	{
		printf("\n%d : %d\n", i, st->array[i]);
	}
}

int main(int ac, char **av)
{
	t_stack *astack;
	t_stack *bstack;
	char *line;

	if (ac < 2 || !(astack = ft_check_arg(&av[1])))
	{
		ft_putendl_fd(ERROR_MESSAGE, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	bstack = ft_calloc(1, sizeof(t_stack));
	bstack->array_size = 0;
	bstack->array = ft_calloc(1, sizeof(int));
	// test_stack(astack);
	while (get_next_line(STDIN_FILENO, &line))
	{
		ft_get_operation(astack, bstack, line);
		free(line);
		printf("\nastack :\n");
		ft_display_stack(astack);
		printf("\nbstack :\n");
		ft_display_stack(bstack);
		// if (!bstack->array_size && ft_isordered(astack))
		// {
		// 	ft_putendl_fd("OK\n", STDERR_FILENO);
		// 	return (EXIT_SUCCESS);
		// }
	}
	free(astack);
	return (EXIT_SUCCESS);
}