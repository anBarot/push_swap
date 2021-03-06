/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_algo_small.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:14:24 by abarot            #+#    #+#             */
/*   Updated: 2021/05/03 15:24:00 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_lighten_str(char *res)
{
	char	*tmp;

	tmp = res;
	res = ft_replace_in_str(res, "ra\nrb\n", "rr\n");
	free(tmp);
	tmp = res;
	res = ft_replace_in_str(res, "rra\nrrb\n", "rrr\n");
	free(tmp);
	tmp = res;
	res = ft_replace_in_str(res, "sa\nsb\n", "ss\n");
	free(tmp);
	tmp = res;
	res = ft_replace_in_str(res, "sa\npb\nrra\npa\n", "sa\nrra\nsa\n");
	free(tmp);
	tmp = res;
	res = ft_replace_in_str(res, "pb\nra\npa\n", "sa\nra\n");
	free(tmp);
	return (res);
}

int		ft_is_smallest(size_t value, t_algos algos)
{
	if (value > ft_strlen(algos.s_one_solution) ||
		value > ft_strlen(algos.s_two_solution) ||
		value > ft_strlen(algos.selec_solution))
		return (0);
	return (1);
}

char	*get_smallest(t_algos algos)
{
	if (ft_is_smallest(ft_strlen(algos.s_one_solution), algos))
		return (algos.s_one_solution);
	else if (ft_is_smallest(ft_strlen(algos.s_two_solution), algos))
		return (algos.s_two_solution);
	else
		return (algos.selec_solution);
}

char	*check_algo_small(t_stack *ast, t_stack *bst)
{
	t_algos algos;
	t_stack	*tmp;
	char	*res;

	if (!(tmp = ft_calloc(1, sizeof(t_stack))) ||
		!(tmp->array = ft_calloc(ast->array_size + 1, sizeof(int))))
		return (NULL);
	tmp->array_size = ast->array_size;
	ft_memcpy(tmp->array, ast->array, sizeof(int) * ast->array_size);
	algos.s_one_solution = simplest_sort_algo_1(tmp, bst);
	ft_memcpy(tmp->array, ast->array, sizeof(int) * ast->array_size);
	algos.s_two_solution = simplest_sort_algo_2(tmp, bst);
	ft_memcpy(tmp->array, ast->array, sizeof(int) * ast->array_size);
	algos.selec_solution = selection_sort(tmp, bst);
	ft_clear_stack(tmp);
	algos.s_one_solution = ft_lighten_str(algos.s_one_solution);
	algos.s_two_solution = ft_lighten_str(algos.s_two_solution);
	algos.selec_solution = ft_lighten_str(algos.selec_solution);
	res = ft_strdup(get_smallest(algos));
	free(algos.s_one_solution);
	free(algos.s_two_solution);
	free(algos.selec_solution);
	return (res);
}
