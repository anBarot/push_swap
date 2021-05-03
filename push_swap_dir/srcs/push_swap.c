/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:04:29 by abarot            #+#    #+#             */
/*   Updated: 2021/05/03 12:33:52 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_sorting_algo(t_stack *ast, t_stack *bst)
{
	char	*res;
	int		special;

	if ((special = is_special_case(ast)))
	{
		res = do_special_case(ast, bst, special);
		write(STDOUT_FILENO, res, ft_strlen(res));
		free(res);
	}
	else if (ast->array_size <= 10)
		check_algo_small(ast, bst);
	else
	{
		res = selection_sort_chunked(ast, bst, ast->array_size / 11);
		write(STDOUT_FILENO, res, ft_strlen(res));
		free(res);
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
	if (!is_sorted(ast->array, ast->array_size, FALSE))
	{
		ft_check_sorting_algo(ast, bst);
	}
	ft_clear_stack(ast);
	ft_clear_stack(bst);
	return (EXIT_SUCCESS);
}
