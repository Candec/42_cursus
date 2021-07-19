#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct		s_node
{
	struct s_node	*next;
	struct s_node	*last;
	int				n;
}					t_node;

typedef struct		s_todo
{
	struct s_todo	*next;
	struct s_todo	*prec;
	char			order;
	char			invert;
}					t_todo;

typedef struct		s_stacks
{
	t_node			**a;
	t_node			**b;
}					t_stacks;

/*
** Prototypes
*/
int		push_swap(int a[]);
void	ft_stack_init(char *stack[], int i, t_list **a);
int		parse(char *str, t_node **node, int *err);



// void	visualize_stack(t_list *a, t_list *b);

#endif
