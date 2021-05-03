/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplest_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:17:58 by abarot            #+#    #+#             */
/*   Updated: 2021/05/03 14:04:03 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*simplest_sort_algo_1(t_stack *ast, t_stack *bst)
{
	char *res;

	display_header(*ast, *bst, "Simplest sort 1 :\n\n");
	if (!(res = ft_calloc(1, 1)))
		return (0);
	while (bst->array_size || !is_sorted(ast->array, ast->array_size, FALSE))
	{
		if (ast->array[0] > ast->array[1])
			res = ft_do_action_sta(res, &ft_st_swap, ast, bst);
		else if ((ast->array[0] > ast->array[ast->array_size - 1]
					&& ast->array[0] > ast->array[ast->array_size - 2]))
			res = ft_do_action_sta(res, &ft_st_rot, ast, bst);
		else if (ast->array[0] > ast->array[ast->array_size - 1])
			res = ft_do_action_sta(res, &ft_st_revrot, ast, bst);
		else if (!is_sorted(ast->array, ast->array_size, FALSE))
			res = ft_do_pushb(res, ast, bst);
		else if (bst->array_size)
			res = ft_do_pusha(res, ast, bst);
	}
	return (res);
}

char	*simplest_sort_algo_2(t_stack *ast, t_stack *bst)
{
	char *res;

	display_header(*ast, *bst, "\nSimplest sort 2 :\n\n");
	if (!(res = ft_calloc(1, 1)))
		return (0);
	while (bst->array_size || !is_sorted(ast->array, ast->array_size, FALSE))
	{
		if ((ast->array[0] > ast->array[ast->array_size - 1]
				&& ast->array[0] > ast->array[ast->array_size - 2]))
			res = ft_do_action_sta(res, &ft_st_rot, ast, bst);
		else if (ast->array[0] > ast->array[ast->array_size - 1])
			res = ft_do_action_sta(res, &ft_st_revrot, ast, bst);
		else if (ast->array[0] > ast->array[1])
			res = ft_do_action_sta(res, &ft_st_swap, ast, bst);
		else if (!is_sorted(ast->array, ast->array_size, FALSE))
			res = ft_do_pushb(res, ast, bst);
		else if (bst->array_size)
			res = ft_do_pusha(res, ast, bst);
	}
	return (res);
}

char	*selection_sort(t_stack *ast, t_stack *bst)
{
	char	*res;

	display_header(*ast, *bst, "\nSelection sort :\n\n");
	if (!(res = ft_calloc(1, 1)))
		return (NULL);
	while (ast->array_size != 2 && !is_sorted(ast->array, ast->array_size,
			FALSE))
		res = push_min(ast, bst, res);
	if (!is_sorted(ast->array, ast->array_size, FALSE))
		res = ft_do_action_sta(res, &ft_st_swap, ast, bst);
	while (bst->array_size)
		res = ft_do_pusha(res, ast, bst);
	return (res);
}
