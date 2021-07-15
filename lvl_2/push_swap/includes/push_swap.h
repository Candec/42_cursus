#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int 			content;
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
	struct s_node	*head;
	int				size;
}				t_stack;

typedef struct s_stacks
{
	struct s_stack	*a;
	struct s_stack	*b;
}				t_stacks;

/*
** Prototypes
*/
int		push_swap(int a[]);
void	ft_stack_init(char *stack[], int i, t_list **a);
int 	parse(int argc, char *argv[], t_stacks stacks);

// void	visualize_stack(t_list *a, t_list *b);

#endif
