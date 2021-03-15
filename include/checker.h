#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# define ERROR_MESSAGE	"Error"

typedef struct	s_stack
{
	int 		*array;
	int			array_size;
}				t_stack;

int	ft_get_operation(t_stack **astack, t_stack **bstack, char *line);
t_stack	*ft_pop(t_stack *st);
t_stack	*ft_push(t_stack *st, int nb);
void	ft_st_push(t_stack **fst_stack, t_stack **sec_stack);
void	ft_st_revrot(t_stack *stack);
void	ft_st_rot(t_stack *stack);
void	ft_st_swap(t_stack *stack);
void	ft_clear_stack(t_stack *st);
int	ft_isordered(t_stack *astack);
t_stack	*ft_check_arg(char **arg);
void ft_display_stack(t_stack *ast, t_stack *bst);
t_stack *ft_init_bstack();

#endif