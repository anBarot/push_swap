#include "push_swap.h"

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

char	*push_max(t_stack *ast, t_stack *bst, char *res)
{
	int max;

	max = ft_get_max(*ast);
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

char	*ft_chunked_sort(t_stack *ast, t_stack *bst, int pivot, char *res)
{
	printf("\nchunked sort\n");
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
	if (C_SB)
		res = ft_do_action_stb(res, &ft_st_swap, bst);
	return (res);
}

char	*selection_sort_chunked(t_stack *ast, t_stack *bst)
{
	int n;
	int *sorted_array;
	int pivot_value;
	char *res;

	printf("\nselection sort chunked\n");
	res = ft_calloc(1, 1);
	sorted_array = ft_memcpy(ft_calloc(ast->array_size + 1, sizeof(int)),
					ast->array, ast->array_size * sizeof(int));
	printf("\nsorted array : ");
	for (int i = 0; i < ast->array_size; i++)
	{
		printf("%d, ", sorted_array[i]);
	}
	while (1);
	// ft_sort_array(sorted_array, ast->array_size);
	// printf("\nsorted array : ");
	// for (int i = 0; i < ast->array_size; i++)
	// 	printf("%d, ", sorted_array[i]);
	n = 1;
	ft_display_stack(ast, bst);
	while (ast->array_size > n * 20)
	{
		pivot_value = sorted_array[n * 20];
		printf("\npivot : %d, n * 20 : %d\n", pivot_value, n * 20);
		while (bst->array_size < n * 20)
		{
			res = ft_chunked_sort(ast, bst, pivot_value, res);
		}
		n++;
	}
	ft_display_stack(ast, bst);
	while (1);
	while (ast->array_size)
		res = push_min(ast, bst, res);
	while (bst->array_size)
		res = push_max(ast, bst, res);
	return (res);
}
