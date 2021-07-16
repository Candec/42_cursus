#include "../includes/push_swap.h"

static int	compare(char **strs, int i)
{
	while (strs[i] != NULL)
	{
		if (!ft_isnumber(strs[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse_int(int argc, char *argv[])
{
	int		i;
	int		rtr;
	char	**store;

	if (argc <= 1)
		return (0);
	else if (argc == 2)
	{
		if (ft_strchr(argv[1], ' '))
			rtr = compare(ft_split(argv[1], ' '), 0);
		else if (!ft_isnumber(argv[1]))
			return (0);
	}
	else
		rtr = compare(argv, 1);

		// Look for repeated arguments

	return (rtr);
}
