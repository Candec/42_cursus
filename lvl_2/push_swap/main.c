#include "./includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*node;
	char	*str;
	int		verbose;

	node = NULL;
	str = ft_strmerge(argv + 1, 1, argc - 1);
	if (!(parse(str, &node, &verbose) < 1 || verbose))
		return (0);
	return (1);
}
