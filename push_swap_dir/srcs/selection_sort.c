/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:09:50 by abarot            #+#    #+#             */
/*   Updated: 2021/04/27 18:46:26 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_get_min(t_stack ast)
{
	int min;
	int i;

	i = 1;
	min = ast.array[0];
	while (i < ast.array_size)
	{
		if (min > ast.array[i])
			min = ast.array[i];
		i++;
	}
	return (min);
}

int		ft_search_in_stack(t_stack ast, int nb)
{
	int i;

	i = 0;
	while (i < ast.array_size)
	{
		if (ast.array[i] == nb)
			return (i);
		i++;
	}
	return (0);
}

char	*push_min(t_stack *ast, t_stack *bst, char *res)
{
	int min;

	min = ft_get_min(*ast);
	if (ft_search_in_stack(*ast, min) < (ast->array_size) / 2)
		while (ast->array[0] != min)
		{
			res = ft_do_action_sta(res, &ft_st_rot, ast);
		}
	else
		while (ast->array[0] != min)
		{
			res = ft_do_action_sta(res, &ft_st_revrot, ast);
		}
	res = ft_do_pushb(res, ast, bst);
	return (res);
}

char	*selection_sort(t_stack *ast, t_stack *bst)
{
	char *res;

	if (!(res = ft_calloc(1, 1)))
		return (NULL);
	while (ast->array_size != 2 && !ft_issorted(ast))
		res = push_min(ast, bst, res);
	if (!ft_issorted(ast))
		res = ft_do_action_sta(res, &ft_st_swap, ast);
	while (bst->array_size)
		res = ft_do_pusha(res, ast, bst);
	return (res);
}
