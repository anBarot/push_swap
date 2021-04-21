#include "push_swap.h"
#include <signal.h>

int	ft_is_smallest(size_t value, t_algos algos)
{
	if (value > ft_strlen(S_SONE) || value > ft_strlen(S_STWO) ||
		value > ft_strlen(S_SELECSORT))
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
	t_algos algos;
	t_stack	*tmp;

	if (!(tmp = ft_calloc(1, sizeof(t_stack))) || 
		!(tmp->array = ft_calloc(ast->array_size + 1, sizeof(int))))
		return ;
	tmp->array_size = ast->array_size;
	ft_memcpy(tmp->array, ast->array, sizeof(int) * ast->array_size);
	S_SONE = simplest_sort_algo_1(tmp, bst);
	ft_memcpy(tmp->array, ast->array, sizeof(int) * ast->array_size);
	S_STWO = simplest_sort_algo_2(tmp, bst);
	ft_memcpy(tmp->array, ast->array, sizeof(int) * ast->array_size);
	S_SELECSORT = selection_sort(tmp, bst);
	ft_clear_stack(tmp);
	if (ft_is_smallest(ft_strlen(S_SONE), algos))
		ft_putstr_fd(S_SONE, STDOUT_FILENO);
	else if (ft_is_smallest(ft_strlen(S_STWO), algos))
		ft_putstr_fd(S_STWO,STDOUT_FILENO);
	else
		ft_putstr_fd(S_SELECSORT,STDOUT_FILENO);
	free(algos.s_one_solution);
	free(algos.s_two_solution);
	free(algos.selec_solution);
}

void	ft_check_sorting_algo(t_stack *ast, t_stack *bst)
{
	char *str_selec;
	// char *str_chunk;
	t_stack *tmp;

	if (ast->array_size == 2)
	{
		ft_st_swap(ast);
		ft_putendl_fd("sa\n", STDOUT_FILENO);
		return ;
	}
	else if (ft_isreversed(ast))
	{
		sort_reversed(ast, bst);
		return ;
	}
	else if (ast->array_size < 10)
		ft_check_algo(ast, bst);
	else
	{
		if (!(tmp = ft_calloc(1, sizeof(t_stack))) || 
			!(tmp->array = ft_calloc(ast->array_size + 1, sizeof(int))))
			return ;
		tmp->array_size = ast->array_size;
		ft_memcpy(tmp->array, ast->array, sizeof(int) * ast->array_size);
		str_selec = selection_sort(tmp, bst);
		// ft_display_stack(tmp, bst);
		// exit(1);
		// ft_memcpy(tmp->array, ast->array, sizeof(int) * ast->array_size);
		// str_chunk = selection_sort_chunked(tmp, bst);
		// // printf("\nselec : %zu, chunked : %zu\n", ft_strlen(str_selec), ft_strlen(str_chunk));
		// if (ft_strlen(str_selec) < ft_strlen(str_chunk))
			write(STDOUT_FILENO, str_selec, ft_strlen(str_selec));
		// else
		// 	ft_putstr_fd(str_chunk, STDOUT_FILENO);
		free(str_selec);
		ft_clear_stack(tmp);
		// free(str_chunk);
	}
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
	ft_clear_stack(ast);
	ft_clear_stack(bst);
	return (EXIT_SUCCESS);
}
