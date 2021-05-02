/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sorted_chunks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:10:35 by abarot            #+#    #+#             */
/*   Updated: 2021/05/02 15:31:03 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted_chunk(int *array, int begin, int size)
{
	while (size)
	{
		if (array[begin] > array[begin + 1])
			return (FALSE);
		size--;
		begin++;
	}
	return (TRUE);
}

int		*get_sorted_chunks(t_stack ast)
{
	int	begin;
	int	size;
	int	*list;
	int	i_list;

	list = ft_calloc(sizeof(int), ast.array_size);
	i_list = 0;
	begin = 0;
	size = 1;
	while (begin != ast.array_size)
	{
		while (size < ast.array_size - begin 
			&& is_sorted_chunk(ast.array, begin, size) == TRUE)
			size++;
		list[i_list] = begin + size - 1;
		begin = begin + size;
		size = 1;
		i_list++;
	}
	list[i_list] = -1;
	return (list);
}

int		is_sorted_if_rotated(t_stack ast)
{
	int 	*sorted_chunks;
	int		res;

	res = 0;
	sorted_chunks = get_sorted_chunks(ast);
	if (sorted_chunks[2] == -1)
	{
		if (ast.array[0] > ast.array[sorted_chunks[1]])
			res = sorted_chunks[1] - sorted_chunks[0];
	}
	free(sorted_chunks);
	return (res);
}
