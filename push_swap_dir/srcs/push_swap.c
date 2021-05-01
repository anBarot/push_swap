/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:04:29 by abarot            #+#    #+#             */
/*   Updated: 2021/05/01 14:58:40 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_sorting_algo(t_stack *ast, t_stack *bst)
{
	char	*str_chunk;

	if (ast->array_size == 2)
	{
		ft_st_swap(ast);
		ft_putendl_fd("sa", STDOUT_FILENO);
		return ;
	}
	else if (ast->array_size <= 10)
		check_algo_small(ast, bst);
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
