/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 14:51:27 by abarot            #+#    #+#             */
/*   Updated: 2021/04/29 14:54:20 by abarot           ###   ########.fr       */
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

int		ft_get_max(t_stack ast)
{
	int max;
	int i;

	i = 1;
	max = ast.array[0];
	while (i < ast.array_size)
	{
		if (max < ast.array[i])
			max = ast.array[i];
		i++;
	}
	return (max);
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

char	*push_max(t_stack *ast, t_stack *bst, char *res)
{
	int max;

	max = ft_get_max(*bst);
	if (ft_search_in_stack(*bst, max) < (bst->array_size) / 2)
		while (bst->array[0] != max)
		{
			res = ft_do_action_stb(res, &ft_st_rot, bst);
		}
	else
		while (bst->array[0] != max)
		{
			res = ft_do_action_stb(res, &ft_st_revrot, bst);
		}
	res = ft_do_pusha(res, ast, bst);
	return (res);
}
