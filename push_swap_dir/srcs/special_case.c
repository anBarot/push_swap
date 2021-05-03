/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:01:59 by abarot            #+#    #+#             */
/*   Updated: 2021/05/03 14:02:33 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*insert_first_element(char *res, t_stack *ast, t_stack *bst)
{
	res = ft_do_pushb(res, ast, bst);
	if (bst->array[0] < ast->array[ast->array_size / 2])
	{
		while (bst->array[0] > ast->array[0])
			res = ft_do_action_sta(res, &ft_st_rot, ast, bst);
		res = ft_do_pusha(res, ast, bst);
		while (!is_sorted(ast->array, ast->array_size, FALSE))
			res = ft_do_action_sta(res, &ft_st_revrot, ast, bst);
	}
	else
	{
		while (bst->array[0] < ast->array[ast->array_size - 1])
			res = ft_do_action_sta(res, &ft_st_revrot, ast, bst);
		res = ft_do_pusha(res, ast, bst);
		while (!is_sorted(ast->array, ast->array_size, FALSE))
			res = ft_do_action_sta(res, &ft_st_rot, ast, bst);
	}
	return (res);
}

char	*sort_reversed(char *res, t_stack *ast, t_stack *bst)
{
	while (ast->array_size != 3)
	{
		res = ft_do_action_sta(res, &ft_st_revrot, ast, bst);
		res = ft_do_pushb(res, ast, bst);
	}
	res = ft_do_action_sta(res, &ft_st_swap, ast, bst);
	res = ft_do_action_sta(res, &ft_st_revrot, ast, bst);
	while (bst->array_size)
		res = ft_do_pusha(res, ast, bst);
	return (res);
}

int		is_special_case(t_stack *ast)
{
	if (is_sorted(ast->array + 1, ast->array_size - 1, FALSE))
	{
		if (ast->array[0] == ft_get_max(*ast))
			return (INTRO_MAX);
		return (INTRO_NB_FIRST);
	}
	else if (is_sorted(ast->array, ast->array_size - 1, FALSE))
	{
		if (ast->array[ast->array_size - 1] == ft_get_min(*ast))
			return (INTRO_MIN);
		return (INTRO_NB_LAST);
	}
	else if (is_sorted(ast->array, ast->array_size, TRUE))
		return (REVERSED);
	return (NO_SPECIAL);
}

char	*do_special_case(t_stack *ast, t_stack *bst, int special)
{
	char	*res;

	display_header(*ast, *bst, "Special case :\n\n");
	if (!(res = ft_calloc(1, 1)))
		return (NULL);
	if (special == REVERSED)
		return (res = sort_reversed(res, ast, bst));
	else if (special == INTRO_MAX)
		return (res = ft_do_action_sta(res, &ft_st_rot, ast, bst));
	else if (special == INTRO_NB_LAST || special == INTRO_MIN)
		res = ft_do_action_sta(res, &ft_st_revrot, ast, bst);
	if (special == INTRO_MIN)
		return (res);
	res = insert_first_element(res, ast, bst);
	return (res);
}
