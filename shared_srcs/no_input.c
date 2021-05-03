/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:51:56 by abarot            #+#    #+#             */
/*   Updated: 2021/05/03 17:17:34 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		no_input(char **av, int ac)
{
	if (ac == 1)
		return (TRUE);
	else if (ac == 2)
	{
		if (!ft_strncmp(av[1], "-c", 3) || !ft_strncmp(av[1], "-v", 3) ||
		!ft_strncmp(av[1], "-cv", 4) || !ft_strncmp(av[1], "-vc", 4))
			return (TRUE);
	}
	else if (ac == 3)
	{
		if ((!ft_strncmp(av[1], "-v", 3) && !ft_strncmp(av[2], "-c", 3)) ||
			(!ft_strncmp(av[1], "-c", 3) && !ft_strncmp(av[2], "-v", 3)))
			return (TRUE);
	}
	return (FALSE);
}

void	ft_clear_stack(t_stack *st)
{
	free(st->array);
	free(st);
}
