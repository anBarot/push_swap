/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:03:46 by abarot            #+#    #+#             */
/*   Updated: 2021/04/21 18:04:15 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_st_push(t_stack *fst, t_stack *sec)
{
	if (sec->array_size)
	{
		fst->array[fst->array_size] = sec->array[0];
		fst->array_size = fst->array_size + 1;
		ft_st_revrot(fst);
		ft_st_rot(sec);
		sec->array_size = sec->array_size - 1;
	}
	return (PUSH_A);
}

int		ft_st_revrot(t_stack *stack)
{
	int tmp;
	int i;

	i = stack->array_size - 1;
	if (stack->array_size > 1)
	{
		tmp = stack->array[i];
		while (i > 0)
		{
			stack->array[i] = stack->array[i - 1];
			i--;
		}
		stack->array[i] = tmp;
	}
	return (RROT_A);
}

int		ft_st_rot(t_stack *stack)
{
	int tmp;
	int i;

	i = 0;
	if (stack->array_size > 1)
	{
		tmp = stack->array[i];
		while (i < (stack->array_size - 1))
		{
			stack->array[i] = stack->array[i + 1];
			i++;
		}
		stack->array[i] = tmp;
	}
	return (ROT_A);
}

int		ft_st_swap(t_stack *stack)
{
	if (stack->array_size > 1)
		ft_swap(&stack->array[0], &stack->array[1]);
	return (SWAP_A);
}
