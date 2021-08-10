#include "./includes/push_swap.h"

int	countitem(t_node *node)
{
	int	i;
	t_node *cur;

	i = 0;
	cur = node;
	while (node && ++i && cur->next != node)
		cur = cur->next;
	return (i);
}

int	is_sorted(t_node *node, int until)
{
	t_node	*cur;
	int		i;

	i = 1;
	cur = node;
	while (cur->next != node && cur->n < cur->next->n)
	{
		cur = cur->next;
		i++;
	}
	return (i >= until);
}

static void	makeinstruct(t_node **a)
{
	t_stacks	stacks;
	t_node		*b;
	t_todo		**list;
	int			size;

	b = NULL;
	stacks.a = a;
	stacks.b = &b;
	size = countitem(*(stacks.a));
	if (!is_sorted(*(stacks.a), size))
	{
		if (size <= 3)
			small_sort(stacks);
		else
		 	quicksort(stacks, size, 1, 2);
		list = get_list();
		while (del(list))
			 ;
		print_orders();
	}
}

int	main(int argc, char *argv[])
{
	t_node	*node;
	char	*str;
	int		verbose;

	node = NULL;
	str = ft_strmerge(argv + 1, 1, argc - 1);
	if (!(parse(str, &node, &verbose) < 1 || verbose))
		makeinstruct(&node);
	else if (argc > 1)
		write(1, "Error\n", 7);
	ft_strdel(&str);
	return (0);
}