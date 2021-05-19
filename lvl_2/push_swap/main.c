#include "./includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_list *a;

	a = NULL;
	if (argc == 1)
		return (1);
	ft_stack_init(argv + 1, argc - 1, &a);
	while (a != NULL)
	{
		printf("%lld\n", (long long)a->content);
		a = a->next;
	}
}
