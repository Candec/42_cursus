#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*last;
	int				n;
}					t_node;

typedef struct s_todo
{
	struct s_todo	*next;
	struct s_todo	*prec;
	char			order;
	char			invert;
}					t_todo;

typedef struct s_stacks
{
	t_node			**a;
	t_node			**b;
}					t_stacks;

enum{PA, PB, SA, SB, SS, RA, RB, RR, RRA , RRB, RRR};

/*
** Prototypes
*/
int		parse(char *str, t_node **node, int *err);
int		countitem(t_node *node);
void	small_sort(t_stacks stacks);
void	do_order(char order, t_node **a, t_node **b);
char	*str_order(char order);
t_todo	**get_list(void);
void	add_order(t_todo **todo, char order);
char	invert(char order);
int		is_opposite(char order, char ref);
int		apply(char *str, t_node **a, t_node **b);
void	print_orders(void);
int		is_sorted(t_node *node, int until, int sorted);
void	quicksort(t_stacks p, int until, int apile, int fiter);
int		is_blocking(char order1, char order2);
int		del(t_todo **list);
int		median(t_node *pile, int size);
void	sort3(t_node **a, t_node **b, int until, int sorted);
int		act(t_node **a, t_node **b, int sorted, int pivot);
void	next_quicksort(t_stacks p, int until, int sorted, int fiter);
int		get_median(int sorted, t_stacks p, int until);
void	RRARRB(int sorted, t_stacks p);
void	fitest(int i, int sorted, t_stacks p, int fiter);
void	inverter(int i, int sorted, t_stacks p);
bool	get_sorted(int sorted, t_stacks p, int until);
void	del_node(t_node **list);
int		del_stacks(t_stacks stacks);
int		ft_ordersize(t_todo *lst);
void	del_orders(t_todo **list);

#endif
