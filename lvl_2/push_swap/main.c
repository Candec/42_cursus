#include "./includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_list *a;
	t_list *b;

	a = 0;
	b = 0;
	if (argc == 1)
		return (1);
	ft_stack_init(argv + 1, argc - 1, &a);
}
