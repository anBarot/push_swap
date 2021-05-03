/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort_chunked.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:24:33 by abarot            #+#    #+#             */
/*   Updated: 2021/05/03 14:16:53 by abarot           ###   ########.fr       */
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

char	*posi_and_push(t_stack *ast, t_stack *bst, int pivot, char *res)
{
	int upper_posi;
	int down_posi;

	upper_posi = ft_get_posi(*ast, pivot, UP);
	down_posi = ft_get_posi(*ast, pivot, DOWN);
	if (upper_posi < (ast->array_size - down_posi) ||
		((upper_posi == (ast->array_size - down_posi)) &&
		(ast->array[upper_posi] <= ast->array[down_posi])))
		while (upper_posi)
		{
			res = ft_do_action_sta(res, &ft_st_rot, ast, bst);
			upper_posi--;
		}
	else
		while (ast->array_size != down_posi)
		{
			res = ft_do_action_sta(res, &ft_st_revrot, ast, bst);
			down_posi++;
		}
	res = ft_do_pushb(res, ast, bst);
	return (res);
}

int		*create_sorted_array(t_stack *ast)
{
	int		*sorted_array;

	if (!(sorted_array = ft_calloc(ast->array_size + 1, sizeof(int))))
		return (NULL);
	ft_memcpy(sorted_array, ast->array, ast->array_size * sizeof(int));
	ft_sort_array(sorted_array, ast->array_size);
	return (sorted_array);
}

char	*selection_sort_chunked(t_stack *ast, t_stack *bst, int chunk_len)
{
	int		n;
	int		*sorted_array;
	int		pivot_value;
	char	*res;

	display_header(*ast, *bst, "Selection sort chunked :\n\n");
	sorted_array = create_sorted_array(ast);
	if (!(res = ft_calloc(1, 1)) || !sorted_array)
		return (NULL);
	n = 1;
	while (ast->array_size > (n * chunk_len) &&
			!is_sorted(ast->array, ast->array_size, FALSE))
	{
		pivot_value = sorted_array[n * chunk_len];
		while (bst->array_size < (n * chunk_len) &&
				!is_sorted(ast->array, ast->array_size, FALSE))
			res = posi_and_push(ast, bst, pivot_value, res);
		n++;
	}
	while (ast->array_size && !is_sorted(ast->array, ast->array_size, FALSE))
		res = push_min(ast, bst, res);
	while (bst->array_size)
		res = push_max(ast, bst, res);
	free(sorted_array);
	return (res);
}
