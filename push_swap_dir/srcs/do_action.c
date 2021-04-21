/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:58:04 by abarot            #+#    #+#             */
/*   Updated: 2021/04/21 12:14:31 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_do_action_sta(char *res, int (*action)(t_stack *), t_stack *stack)
{
	char *tmp;
	int dspl;
	char **str_list;

	str_list = 
	ft_split("sa\n;sb\n;ss\n;pa\n;pb\n;ra\n;rb\n;rr\n;rra\n;rrb\n;rrr\n", ';');
	dspl = action(stack);
	tmp = res;
	res = ft_strjoin(res, str_list[dspl]);
	free(tmp);
	ft_clear_map(str_list);
	return (res);
}

char	*ft_do_action_stb(char *res, int (*action)(t_stack *), t_stack *stack)
{
	char *tmp;
	int dspl;
	char **str_list;

	str_list = 
	ft_split("sa\n;sb\n;ss\n;pa\n;pb\n;ra\n;rb\n;rr\n;rra\n;rrb\n;rrr\n", ';');
	dspl = action(stack) + 1;
	tmp = res;
	res = ft_strjoin(res, str_list[dspl]);
	free(tmp);
	ft_clear_map(str_list);
	return (res);
}

char	*ft_do_pushb(char *res, t_stack *ast, t_stack *bst)
{
	char *tmp;

	ft_st_push(bst, ast);
	tmp = res;
	res = ft_strjoin(res, "pb\n");
	free(tmp);
	return (res);
}

char	*ft_do_pusha(char *res, t_stack *ast, t_stack *bst)
{
	char *tmp;

	ft_st_push(ast, bst);
	tmp = res;
	res = ft_strjoin(res, "pa\n");
	free(tmp);
	return (res);
}
