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

#endif