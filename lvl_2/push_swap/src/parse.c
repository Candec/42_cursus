#include "../includes/push_swap.h"

int parse_int(int argc, char *argv[])
{
	int i;
	char **store;

	if (argc <= 1)
		return (0);
	else if (argc == 2)
		if (ft_strchr(argv[1], ' '))
		{
			i = 0;
			store = ft_split(argv[1], ' ');
			while (store[i] != NULL)
			{
				if (!ft_isnumber(store[i]))
					return (0);
				i++;
			}
		}
		else if (!ft_isnumber(argv[1]))
			return (0);
	else
	{
		i = 1;
		while (argv[i] != NULL)
		{
			if (!ft_isnumber(argv[i]))
				return (0);
			i++;
		}
	}
return 1;
}
