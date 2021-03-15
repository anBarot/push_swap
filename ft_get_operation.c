#include "push_swap.h"

t_stack	*ft_pop(t_stack *st)
{
	t_stack *n_stack;
	int i;

	i = 0;
	n_stack = ft_calloc(1, sizeof(t_stack));
	n_stack->array_size = st->array_size - 1;
	n_stack->array = ft_calloc(n_stack->array_size + 1, sizeof(int));
	while (i < n_stack->array_size)
	{
		n_stack->array[i] = st->array[i + 1];
		i++;
	}
	free(st->array);
	free(st);
	return (n_stack);
}

t_stack	*ft_push(t_stack *st, int nb)
{
	t_stack *n_stack;
	int i;

	i = 0;
	n_stack = ft_calloc(1, sizeof(t_stack));
	n_stack->array_size = st->array_size + 1;
	n_stack->array = ft_calloc(n_stack->array_size + 1, sizeof(int));
	while (i < st->array_size)
	{
		n_stack->array[i + 1] = st->array[i];
		i++;
	}
	n_stack->array[0] = nb;
	free(st->array);
	free(st);
	return (n_stack);
}

void	ft_st_push(t_stack *fst_stack, t_stack *sec_stack)
{
	int i_fst;
	int i_sec;
	
	if (sec_stack->array_size > 0)
	{
		fst_stack = ft_push(fst_stack, sec_stack->array[0]);
		sec_stack = ft_pop(sec_stack);
	}
}

void	ft_st_revrot(t_stack *stack)
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
}

void	ft_st_rot(t_stack *stack)
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
}

void	ft_st_swap(t_stack *stack)
{
	if (stack->array_size > 1)
		ft_swap(&stack->array[0], &stack->array[1]);
}

int	ft_get_operation(t_stack *astack, t_stack *bstack, char *line) 
{
	if (!(ft_strncmp(line, "sa", 3)) || !(ft_strncmp(line, "ss", 3)))
		ft_st_swap(astack);
	if (!(ft_strncmp(line, "sb", 3)) || !(ft_strncmp(line, "ss", 3)))
		ft_st_swap(bstack);
	if (!(ft_strncmp(line, "ra", 3)) || !(ft_strncmp(line, "rr", 3)))
		ft_st_rot(astack);
	if (!(ft_strncmp(line, "rb", 3)) || !(ft_strncmp(line, "rr", 3)))
		ft_st_rot(bstack);
	if (!(ft_strncmp(line, "rra", 4)) || !(ft_strncmp(line, "rrr", 4)))
		ft_st_revrot(astack);
	if (!(ft_strncmp(line, "rrb", 4)) || !(ft_strncmp(line, "rrr", 4)))
		ft_st_revrot(bstack);
	if (!(ft_strncmp(line, "pa", 3)))
		ft_st_push(astack, bstack);
	if (!(ft_strncmp(line, "pb", 3)))
		ft_st_push(bstack, astack);
	return (EXIT_SUCCESS);
}
