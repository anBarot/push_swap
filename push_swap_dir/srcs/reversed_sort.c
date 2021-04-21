/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reversed_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:17:36 by abarot            #+#    #+#             */
/*   Updated: 2021/04/21 18:17:40 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_isreversed(t_stack *ast)
{
	int i;
	int tmp;

	i = 1;
	tmp = ast->array[0];
	while (i < ast->array_size)
	{
		if (tmp < ast->array[i])
			return (0);
		tmp = ast->array[i];
		i++;
	}
	return (1);
}

void	sort_reversed(t_stack *ast, t_stack *bst)
{
	while (ast->array_size != 3)
	{
		ft_putendl_fd("rra", STDOUT_FILENO);
		ft_st_revrot(ast);
		ft_putendl_fd("pb", STDOUT_FILENO);
		ft_st_push(bst, ast);
	}
	ft_putendl_fd("ra", STDOUT_FILENO);
	ft_st_rot(ast);
	ft_putendl_fd("sa", STDOUT_FILENO);
	ft_st_swap(ast);
	while (bst->array_size)
	{
		ft_putendl_fd("pa", STDOUT_FILENO);
		ft_st_push(ast, bst);
	}
}
