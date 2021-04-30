/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:00:35 by abarot            #+#    #+#             */
/*   Updated: 2021/04/30 17:46:07 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_issorted(t_stack *astack)
{
	int tmp;
	int i;

	i = 1;
	tmp = astack->array[0];
	while (i < astack->array_size)
	{
		if (tmp > astack->array[i])
			return (0);
		tmp = astack->array[i];
		i++;
	}
	return (1);
}

int		check_and_add_arg(char *arg, t_stack *ast, int *i_array)
{
	int		i_split;
	char	**str_split;

	str_split = ft_split(arg, ' ');
	i_split = 0;
	while (str_split[i_split])
	{
		if ((!ft_isft_str(str_split[i_split], ft_isdigit)
				&& str_split[i_split][0] != '-') ||
			(!ft_isft_str(str_split[i_split] + 1, ft_isdigit)
				&& str_split[i_split][0] == '-') ||
			(ast->array[*i_array] = ft_atoi(str_split[i_split]))
									!= ft_atol(str_split[i_split]))
			return (EXIT_FAILURE);
		i_split++;
		*i_array = *i_array + 1;
	}
	ft_clear_map(str_split);
	return (EXIT_SUCCESS);
}

int		ft_check_duplicates(t_stack ast)
{
	int	i;
	int j;

	i = 0;
	while (i < ast.array_size - 1)
	{
		j = i + 1;
		while (j < ast.array_size)
		{
			if (ast.array[i] == ast.array[j])
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

t_stack	*ft_check_arg(char **arg)
{
	int		i_arg;
	int		i_array;
	t_stack	*astack;

	i_arg = 0;
	i_array = 0;
	if (!(astack = ft_calloc(1, sizeof(t_stack))) ||
		!(astack->array = ft_calloc(ft_count_line(arg), sizeof(int))))
		return (NULL);
	while (arg[i_arg])
	{
		if (check_and_add_arg(arg[i_arg], astack, &i_array) == EXIT_FAILURE)
			return (NULL);
		i_arg++;
	}
	astack->array_size = i_array;
	if (ft_check_duplicates(*astack) == EXIT_FAILURE)
		return (NULL);
	return (astack);
}

t_stack	*ft_init_bstack(size_t size)
{
	t_stack *bstack;

	if (!(bstack = ft_calloc(1, sizeof(t_stack))) ||
		!(bstack->array = ft_calloc(size, sizeof(int))))
		return (NULL);
	bstack->array_size = 0;
	return (bstack);
}
