#include "./includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_list *a;
	t_list *b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	ft_stack_init(argv + 1, argc - 1, &a);
	visualize_stack(a, b);
	// while (a != NULL || b !=NULL)
	// {
	// 	if (a != NULL)
	// 	{
	// 		printf("%lld	", (long long)a->content);
	// 		a = a->next;
	// 	}
	// 	else
	// 	{
	// 		printf(" 	");
	// 	}
	// 	if (b != NULL)
	// 	{
	// 		printf("%lld\n", (long long)b->content);
	// 		b = b ->next;
	// 	}
	// 	else
	// 	{
	// 		printf(" \n");
	// 	}
	// }
}
