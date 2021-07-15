#include "../includes/push_swap.h"

int parse(int argc, char *argv[], t_stacks stacks)
{
	char **store;
	int i;

	i = 0;
	if (argc <= 1)
		return 0;
	else
		if (argc == 2)
			if (ft_strchr(argv[1], ' '))
			{
				store = ft_split(argv[1], ' ');
				while (store[i] != NULL)
				{
					printf("%s\n", store[i]);
					i++;
				}
			}
			// else if (ft_isnumber(argv[1]))

return 1;

}
