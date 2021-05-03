/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:37:22 by abarot            #+#    #+#             */
/*   Updated: 2021/05/03 13:58:35 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_display_checker(int count, t_stack ast, t_stack bst)
{
	char	*str_count;

	str_count = ft_itoa(count);
	ft_putstr_fd(str_count, STDOUT_FILENO);
	ft_putstr_fd(" :\n", STDOUT_FILENO);
	ft_display_stack(ast, bst);
	free(str_count);
}

int		ft_get_operation(t_stack *astack, t_stack *bstack, char *line)
{
	if (!(ft_strncmp(line, "sa", 3)) || !(ft_strncmp(line, "ss", 3)))
		ft_st_swap(astack);
	else if (!(ft_strncmp(line, "sb", 3)) || !(ft_strncmp(line, "ss", 3)))
		ft_st_swap(bstack);
	else if (!(ft_strncmp(line, "ra", 3)) || !(ft_strncmp(line, "rr", 3)))
		ft_st_rot(astack);
	else if (!(ft_strncmp(line, "rb", 3)) || !(ft_strncmp(line, "rr", 3)))
		ft_st_rot(bstack);
	else if (!(ft_strncmp(line, "rra", 4)) || !(ft_strncmp(line, "rrr", 4)))
		ft_st_revrot(astack);
	else if (!(ft_strncmp(line, "rrb", 4)) || !(ft_strncmp(line, "rrr", 4)))
		ft_st_revrot(bstack);
	else if (!(ft_strncmp(line, "pa", 3)))
		ft_st_push(astack, bstack);
	else if (!(ft_strncmp(line, "pb", 3)))
		ft_st_push(bstack, astack);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	ft_read_operation(t_stack *ast, t_stack *bst)
{
	char	*line;
	int		value;
	int		count;

	count = 0;
	display_header(*ast, *bst, "Checker :\n\n");
	while ((value = get_next_line(STDIN_FILENO, &line)))
	{
		if (value == -1 || ft_get_operation(ast, bst, line) == EXIT_FAILURE)
		{
			ft_putendl_fd(ERROR_MESSAGE, STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		free(line);
		count++;
		if (g_debug == TRUE)
			ft_display_checker(count, *ast, *bst);
	}
	free(line);
}

int		main(int ac, char **av)
{
	t_stack *ast;
	t_stack *bst;

	if (ac == 1)
		return (EXIT_SUCCESS);
	if (!(ast = ft_check_arg(&av[1])) ||
			!(bst = ft_init_bstack(ast->array_size)))
	{
		ft_putendl_fd(ERROR_MESSAGE, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	ft_read_operation(ast, bst);
	if (!bst->array_size && is_sorted(ast->array, ast->array_size, FALSE))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
	{
		ft_putendl_fd("KO", STDOUT_FILENO);
	}
	ft_clear_stack(ast);
	ft_clear_stack(bst);
	return (EXIT_SUCCESS);
}
