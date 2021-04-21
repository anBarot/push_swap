/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplest_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:17:58 by abarot            #+#    #+#             */
/*   Updated: 2021/04/21 18:36:52 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*simplest_sort_algo_1(t_stack *ast, t_stack *bst)
{
	char *res;

	if (!(res = ft_calloc(1, 1)))
		return (0);
	while (bst->array_size || !ft_issorted(ast))
	{
		if (ast->array[0] > ast->array[1])
			res = ft_do_action_sta(res, &ft_st_swap, ast);
		else if ((ast->array[0] > ast->array[ast->array_size - 1]
					&& ast->array[0] > ast->array[ast->array_size - 2]))
			res = ft_do_action_sta(res, &ft_st_rot, ast);
		else if (ast->array[0] > ast->array[ast->array_size - 1])
			res = ft_do_action_sta(res, &ft_st_revrot, ast);
		else if (!ft_issorted(ast))
			res = ft_do_pushb(res, ast, bst);
		else if (bst->array_size)
			res = ft_do_pusha(res, ast, bst);
	}
	return (res);
}

char	*simplest_sort_algo_2(t_stack *ast, t_stack *bst)
{
	char *res;

	if (!(res = ft_calloc(1, 1)))
		return (0);
	while (bst->array_size || !ft_issorted(ast))
	{
		if ((ast->array[0] > ast->array[ast->array_size - 1]
				&& ast->array[0] > ast->array[ast->array_size - 2]))
			res = ft_do_action_sta(res, &ft_st_rot, ast);
		else if (ast->array[0] > ast->array[ast->array_size - 1])
			res = ft_do_action_sta(res, &ft_st_revrot, ast);
		else if (ast->array[0] > ast->array[1])
			res = ft_do_action_sta(res, &ft_st_swap, ast);
		else if (!ft_issorted(ast))
			res = ft_do_pushb(res, ast, bst);
		else if (bst->array_size)
			res = ft_do_pusha(res, ast, bst);
	}
	return (res);
}
