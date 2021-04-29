/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort_chunked.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:24:33 by abarot            #+#    #+#             */
/*   Updated: 2021/04/29 16:59:16 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_get_posi(t_stack ast, int pivot, int direction)
{
	int i;

	if (direction == UP)
	{
		i = 0;
		while (ast.array[i] > pivot)
			i++;
		return (i);
	}
	else if (ast.array_size)
	{
		i = ast.array_size - 1;
		while (i > 0 && ast.array[i] > pivot)
			i--;
		return (i);
	}
	return (0);
}

char	*rehash_stacks(t_stack *ast, t_stack *bst, char *res)
{
	if (bst->array[0] < bst->array[2])
	{
		if (ast->array[0] > ast->array[2] &&
				ast->array[ast->array_size - 1] > ast->array[0])
			res = ft_do_action_both(res, &ft_st_rot, ast, bst);
		else
			res = ft_do_action_stb(res, &ft_st_rot, bst);
	}
	else if (bst->array[0] < bst->array[1])
	{
		if (ast->array[0] > ast->array[1])
			res = ft_do_action_both(res, &ft_st_swap, ast, bst);
		else
			res = ft_do_action_stb(res, &ft_st_swap, bst);
	}
	return (res);
}

char	*ft_chunked_sort(t_stack *ast, t_stack *bst, int pivot, char *res)
{
	int upper_posi;
	int down_posi;

	upper_posi = ft_get_posi(*ast, pivot, UP);
	down_posi = ft_get_posi(*ast, pivot, DOWN);
	if (upper_posi <= (down_posi - (ast->array_size / 2)))
	{
		while (upper_posi)
		{
			res = ft_do_action_sta(res, &ft_st_rot, ast);
			upper_posi--;
		}
	}
	else
	{
		while ((down_posi - ast->array_size) < 0)
		{
			res = ft_do_action_sta(res, &ft_st_revrot, ast);
			down_posi++;
		}
	}
	res = ft_do_pushb(res, ast, bst);
	res = rehash_stacks(ast, bst, res);
	return (res);
}

char	*selection_sort_chunked(t_stack *ast, t_stack *bst)
{
	int		n;
	int		*sorted_array;
	int		pivot_value;
	char	*res;
	int		chunk_len;

	res = ft_calloc(1, 1);
	sorted_array = ft_calloc(ast->array_size + 1, sizeof(int));
	ft_memcpy(sorted_array, ast->array, ast->array_size * sizeof(int));
	ft_sort_array(sorted_array, ast->array_size);
	n = 1;
	chunk_len = ast->array_size / 11;
	while (ast->array_size > (n * chunk_len) && !ft_issorted(ast))
	{
		pivot_value = sorted_array[n * chunk_len];
		while (bst->array_size < (n * chunk_len) && !ft_issorted(ast))
			res = ft_chunked_sort(ast, bst, pivot_value, res);
		n++;
	}
	while (ast->array_size && !ft_issorted(ast))
		res = push_min(ast, bst, res);
	while (bst->array_size)
		res = push_max(ast, bst, res);
	free(sorted_array);
	return (res);
}
