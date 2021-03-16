#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "checker.h"

# define V_MEDIAN	(*ast)->array[(*ast)->array_size / 2]
# define V_FIRST	(*ast)->array[0]
# define V_SECOND	(*ast)->array[1]
# define V_LAST		(*ast)->array[(*ast)->array_size - 1]
# define A_SONE		algo_value.one
# define A_STWO		algo_value.two
# define A_STHREE	algo_value.three
# define FALSE		0
# define TRUE		1

typedef struct	s_algo_value
{
	int			one;
	int			two;
	int			three;
}				t_algo_value;

#endif