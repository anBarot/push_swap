/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:09:50 by abarot            #+#    #+#             */
/*   Updated: 2021/05/01 13:07:38 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

char	*selection_sort(t_stack *ast, t_stack *bst)
{
	char *res;

	if (debug == TRUE)
	{
		write(STDOUT_FILENO, "\nSelection sort :\n\n",
				ft_strlen("\nSelection sort :\n\n"));
		ft_display_stack(*ast, *bst);
	}
	if (!(res = ft_calloc(1, 1)))
		return (NULL);
	while (ast->array_size != 2 && !ft_issorted(ast))
		res = push_min(ast, bst, res);
	if (!ft_issorted(ast))
		res = ft_do_action_sta(res, &ft_st_swap, ast, bst);
	while (bst->array_size)
		res = ft_do_pusha(res, ast, bst);
	return (res);
}
