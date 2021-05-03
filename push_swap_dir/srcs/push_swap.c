/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:04:29 by abarot            #+#    #+#             */
/*   Updated: 2021/05/03 16:53:10 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_result(char *res)
{
	(g_color == TRUE) ? ft_putstr_fd(BOLDGREEN, STDOUT_FILENO) : 0;
	ft_putstr_fd(res, STDOUT_FILENO);
	(g_color == TRUE) ? ft_putstr_fd(RESET, STDOUT_FILENO) : 0;
	free(res);
}

void	ft_check_sorting_algo(t_stack *ast, t_stack *bst)
{
	char	*res;
	int		special;

	if ((special = is_special_case(ast)))
		res = do_special_case(ast, bst, special);
	else if (ast->array_size <= 10)
		res = check_algo_small(ast, bst);
	else
		res = selection_sort_chunked(ast, bst, ast->array_size / 11);
	display_result(res);
}

int		main(int ac, char **av)
{
	t_stack *ast;
	t_stack *bst;

	if (no_input(av, ac) == TRUE)
		return (EXIT_SUCCESS);
	if (!(ast = ft_check_arg(&av[1])) ||
		!(bst = ft_init_bstack(ast->array_size)))
	{
		display_error();
		return (EXIT_FAILURE);
	}
	if (!is_sorted(ast->array, ast->array_size, FALSE))
		ft_check_sorting_algo(ast, bst);
	ft_clear_stack(ast);
	ft_clear_stack(bst);
	return (EXIT_SUCCESS);
}
