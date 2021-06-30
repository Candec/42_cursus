#include "./includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stacks	stacks;

	stacks.a->head = NULL;
	stacks.a->size = 0;
	stacks.b->head = NULL;
	stacks.b->size = 0;


	if (!parse(argc, argv, stacks))
	{
		write(1, "Error\n", 7);
		return(0);
	}
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
