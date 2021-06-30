#include "../includes/push_swap.h"

int parse(int argc, char *argv[], t_stacks stacks)
{
	if (argc <= 1)
		return 0;
	else
		if (argc == 2)
			if (ft_strchr(argv[1], ' '))
				ft_split(argv[1], ' ');
			else if (ft_isnumber(argv[1]))



}
