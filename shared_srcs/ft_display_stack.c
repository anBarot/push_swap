/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 13:42:13 by abarot            #+#    #+#             */
/*   Updated: 2021/05/03 15:52:33 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	display_error(void)
{
	(g_color == TRUE) ? ft_putstr_fd(BOLDRED, STDOUT_FILENO) : 0;
	ft_putendl_fd(ERROR_MESSAGE, STDERR_FILENO);
	(g_color == TRUE) ? ft_putstr_fd(RESET, STDOUT_FILENO) : 0;
}

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
		(g_color == TRUE) ? ft_putstr_fd(BOLDYELLOW, STDOUT_FILENO) : 0;
		write(STDOUT_FILENO, str, ft_strlen(str));
		(g_color == TRUE) ? ft_putstr_fd(RESET, STDOUT_FILENO) : 0;
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
	(g_color == TRUE) ? ft_putstr_fd(BOLDBLUE, STDOUT_FILENO) : 0;
	ft_putstr_fd(tmp, STDOUT_FILENO);
	(g_color == TRUE) ? ft_putstr_fd(RESET, STDOUT_FILENO) : 0;
	free(tmp);
}

void	ft_display_stack(t_stack ast, t_stack bst)
{
	int		i;

	i = 0;
	(g_color == TRUE) ? ft_putstr_fd(BOLDYELLOW, STDOUT_FILENO) : 0;
	ft_putstr_fd(" -----ast----- -----bst-----\n", STDOUT_FILENO);
	(g_color == TRUE) ? ft_putstr_fd(RESET, STDOUT_FILENO) : 0;
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
