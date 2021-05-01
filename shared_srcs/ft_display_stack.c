/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 13:42:13 by abarot            #+#    #+#             */
/*   Updated: 2021/05/01 13:42:27 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_display_stack(t_stack ast, t_stack bst)
{
	int		i;
	int		space_nb;
	char	*tmp;

	i = 0;

	write(STDOUT_FILENO, " -----ast----- -----bst-----\n", 
	ft_strlen(" -----ast----- -----bst-----\n"));
	while (i < ast.array_size || i < bst.array_size)
	{
		if (i < ast.array_size)
		{
			tmp = ft_itoa(ast.array[i]);
			space_nb = 14 - ft_strlen(tmp);
			write(STDOUT_FILENO, "              ", space_nb);
			ft_putstr_fd(tmp, STDOUT_FILENO);
			free(tmp);
		}
		else
			write(STDOUT_FILENO, "              ", 14);
		if (i < bst.array_size)
		{
			tmp = ft_itoa(bst.array[i]);
			space_nb = 14 - ft_strlen(tmp);
			write(STDOUT_FILENO, "              ", space_nb);
			ft_putstr_fd(tmp, STDOUT_FILENO);
			free(tmp);
		}
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
