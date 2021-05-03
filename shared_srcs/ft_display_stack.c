/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 13:42:13 by abarot            #+#    #+#             */
/*   Updated: 2021/05/03 13:56:34 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		is_sorted(int *array, int size, int reverse)
{
	int tmp;
	int i;

	i = 1;
	tmp = array[0];
	if (reverse == FALSE)
		while (i < size)
		{
			if (tmp > array[i])
				return (0);
			tmp = array[i];
			i++;
		}
	else
		while (i < size)
		{
			if (tmp < array[i])
				return (0);
			tmp = array[i];
			i++;
		}
	return (1);
}

void	display_header(t_stack ast, t_stack bst, char *str)
{
	if (g_debug == TRUE)
	{
		write(STDOUT_FILENO, str, ft_strlen(str));
		ft_display_stack(ast, bst);
	}
}

void	ft_display_one_nb(int nb)
{
	char	*tmp;
	int		space_nb;

	tmp = ft_itoa(nb);
	space_nb = 14 - ft_strlen(tmp);
	write(STDOUT_FILENO, "              ", space_nb);
	ft_putstr_fd(tmp, STDOUT_FILENO);
	free(tmp);
}

void	ft_display_stack(t_stack ast, t_stack bst)
{
	int		i;

	i = 0;
	write(STDOUT_FILENO, " -----ast----- -----bst-----\n",
	ft_strlen(" -----ast----- -----bst-----\n"));
	while (i < ast.array_size || i < bst.array_size)
	{
		if (i < ast.array_size)
			ft_display_one_nb(ast.array[i]);
		else
			write(STDOUT_FILENO, "              ", 14);
		if (i < bst.array_size)
			ft_display_one_nb(bst.array[i]);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
