#include "../includes/push_swap.h"

void	visualize_stack(t_list *a, t_list *b)
{
	while (a != NULL || b != NULL)
	{
		if (a != NULL)
		{
			printf("%lld	", (long long)a->content);
			a = a->next;
		}
		else
		{
			printf(" 	");
		}
		if (b != NULL)
		{
			printf("%lld\n", (long long)b->content);
			b = b->next;
		}
		else
		{
			printf(" \n");
		}
	}
	return ;
}
