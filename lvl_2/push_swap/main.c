#include "push_swap.h"



int	main(int argc, char *argv[])
{
	int *a;
	int i;

	i = 0;
	while (i < argc)
	{
		int a = atoi(argv[i]);
		printf("%d\n", a);
		i++;
	}
}
