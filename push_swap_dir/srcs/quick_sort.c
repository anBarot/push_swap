/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:24:33 by abarot            #+#    #+#             */
/*   Updated: 2021/05/04 21:10:40 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*create_sorted_array(t_stack *ast)
{
	int		*sorted_array;

	if (!(sorted_array = ft_calloc(ast->array_size + 1, sizeof(int))))
		return (NULL);
	ft_memcpy(sorted_array, ast->array, ast->array_size * sizeof(int));
	ft_sort_array(sorted_array, ast->array_size);
	return (sorted_array);
}

int	get_median(t_stack *ast, int nb)
{
	int		*sorted_array;
	int		median;

	sorted_array = create_sorted_array(ast);
	median = sorted_array[ast->array_size / nb];
	free(sorted_array);
	return (median);
}

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

char	*quick_sort(t_stack *ast, t_stack *bst, int nb)
{
	int		pivot_value;
	char	*res;

	display_header(*ast, *bst, "Quick sort :\n\n");
	if (!(res = ft_calloc(1, 1)))
		return (NULL);
	while (ast->array_size > 10 && 
			!is_sorted(ast->array, ast->array_size, FALSE))
	{
		pivot_value = get_median(ast, nb);
		while (bst->array_size < pivot_value &&
				!is_sorted(ast->array, ast->array_size, FALSE))
			res = posi_and_push(ast, bst, pivot_value, res);
	}
	while (ast->array_size && !is_sorted(ast->array, ast->array_size, FALSE))
		res = push_min(ast, bst, res);
	while (bst->array_size)
		res = push_max(ast, bst, res);
	return (res);
}
