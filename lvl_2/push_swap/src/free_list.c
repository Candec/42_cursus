#include "../includes/push_swap.h"

int	ft_ordersize(t_todo *lst)
{
	int	a;

	a = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		a++;
	}
	return (a);
}

void	del_orders(t_todo **list)
{
	t_todo	*cur;
	int		size;

	if (!list)
		return ;
	size = ft_ordersize(*list);
	if (size < 0)
		return ;
	cur = *list;
	while (size >= 0)
	{
		if (cur && cur->next)
		{
			cur = (*list)->next;
			free(*list);
			*list = cur;
		}
		size--;
	}
	free(*list);
	return ;
}
