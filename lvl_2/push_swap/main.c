#include "./includes/push_swap.h"

static int		issorted(t_node *node, int until, int anode)
{
	return (ksorted(node, anode) >= until);
}

static void		makeinstruct(t_node **nodea)
{
	t_stacks	stacks;
	t_node		*nodeb;
	t_todo		**list;
	int			size;

	nodeb = NULL;
	stacks.a = nodea;
	stacks.b = &nodeb;
	size = countitem(*(stacks.a));
	if (!issorted(*(stacks.a), size, 1))
	{
		if (size <= 3)
			smallsort(stacks);
		else
			quicksort(stacks, size, 1, 2);
		list = getlist();
		while (del(list))
			;
		printinstruct();
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
		ft_putstr("Error\n");
	ft_strdel(&str);
	return (0);
}
