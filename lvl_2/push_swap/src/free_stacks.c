#include "../includes/push_swap.h"

int	ft_nodesize(t_node *lst)
{
	int		a;
	t_node	*cur;

	a = 0;
	if (!lst)
		return (-1);
	cur = lst->last;
	while (lst != cur)
	{
		lst = lst->next;
		a++;
	}
	return (a);
}

void	del_node(t_node **list)
{
	t_node	*cur;
	int		size;

	if (!list)
		return ;
	size = ft_nodesize(*list);
	if (size < 0)
		return ;
	cur = *list;
	while (size >= 0)
	{
		if (cur && cur->last)
		{
			cur = (*list)->next;
			free(*list);
			*list = cur;
		}
		size--;
	}
	return ;
}

int	del_stacks(t_stacks stacks)
{
	del_node(stacks.a);
	del_node(stacks.b);
	return (0);
}
