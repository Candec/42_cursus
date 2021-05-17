#include "../includes/push_swap.h"

void	ft_stack_init(char *stack[], int len, t_list **a)
{
	int			i;
	long long	tmp;
	t_list		*node;

	i = 0;
	while (i < len)
	{
		tmp = ft_atoi(stack[i]);
		node = ft_lstnew((void *)tmp);
		ft_lstadd_back(a, node);
		i++;
	}
}
