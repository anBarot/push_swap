/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:04:29 by abarot            #+#    #+#             */
/*   Updated: 2021/04/29 11:23:21 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		ft_is_smallest(size_t value, t_algos algos)
{
	if (value > ft_strlen(algos.s_one_solution) ||
		value > ft_strlen(algos.s_two_solution) ||
		value > ft_strlen(algos.selec_solution))
		return (0);
	return (1);
}

char	*ft_lighten_str(char *res)
{
	char	*tmp;

	tmp = res;
	res = ft_replace_in_str(res, "ra\nrb\n", "rr\n");
	free(tmp);
	tmp = res;
	res = ft_replace_in_str(res, "rra\nrrb\n", "rrr\n");
	free(tmp);
	tmp = res;
	res = ft_replace_in_str(res, "sa\nsb\n", "ss\n");
	free(tmp);
	tmp = res;
	res = ft_replace_in_str(res, "sa\npb\nrra\npa\n", "sa\nrra\nsa\n");
	free(tmp);
	tmp = res;
	res = ft_replace_in_str(res, "pb\nra\npa\n", "sa\nra\n");
	free(tmp);
	tmp = res;
	res = ft_replace_in_str(res, "sa\npb\npb\nsa\n", "pb\npb\nss\n");
	free(tmp);
	return (res);
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
	algos.s_one_solution = simplest_sort_algo_1(tmp, bst);
	ft_memcpy(tmp->array, ast->array, sizeof(int) * ast->array_size);
	algos.s_two_solution = simplest_sort_algo_2(tmp, bst);
	ft_memcpy(tmp->array, ast->array, sizeof(int) * ast->array_size);
	algos.selec_solution = selection_sort(tmp, bst);
	ft_clear_stack(tmp);
	algos.s_one_solution = ft_lighten_str(algos.s_one_solution);
	algos.s_two_solution = ft_lighten_str(algos.s_two_solution);
	algos.selec_solution = ft_lighten_str(algos.selec_solution);
	if (ft_is_smallest(ft_strlen(algos.s_one_solution), algos))
		ft_putstr_fd(algos.s_one_solution, STDOUT_FILENO);
	else if (ft_is_smallest(ft_strlen(algos.s_two_solution), algos))
		ft_putstr_fd(algos.s_two_solution, STDOUT_FILENO);
	else
		ft_putstr_fd(algos.selec_solution, STDOUT_FILENO);
	free(algos.s_one_solution);
	free(algos.s_two_solution);
	free(algos.selec_solution);
}

void	ft_check_sorting_algo(t_stack *ast, t_stack *bst)
{
	char	*str_selec;
	char	*str_chunk;
	t_stack	*tmp;

	if (ast->array_size == 2)
	{
		ft_st_swap(ast);
		ft_putendl_fd("sa", STDOUT_FILENO);
		return ;
	}
	else if (ast->array_size <= 10)
		ft_check_algo(ast, bst);
	else if (ast->array_size < 200)
	{
		if (!(tmp = ft_calloc(1, sizeof(t_stack))) ||
			!(tmp->array = ft_calloc(ast->array_size + 1, sizeof(int))))
			return ;
		tmp->array_size = ast->array_size;
		ft_memcpy(tmp->array, ast->array, sizeof(int) * ast->array_size);
		str_selec = selection_sort(tmp, bst);
		ft_memcpy(tmp->array, ast->array, sizeof(int) * ast->array_size);
		str_chunk = selection_sort_chunked(tmp, bst);
		if (ft_strlen(str_selec) < ft_strlen(str_chunk))
			write(STDOUT_FILENO, str_selec, ft_strlen(str_selec));
		else
			write(STDOUT_FILENO, str_chunk, ft_strlen(str_chunk));
		free(str_selec);
		free(str_chunk);
		ft_clear_stack(tmp);
	}
	else
	{
		str_chunk = selection_sort_chunked(ast, bst);
		write(STDOUT_FILENO, str_chunk, ft_strlen(str_chunk));
		free(str_chunk);
	}
}

int		main(int ac, char **av)
{
	t_stack *ast;
	t_stack *bst;

	if (ac < 3 || !(ast = ft_check_arg(&av[1])) ||
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
