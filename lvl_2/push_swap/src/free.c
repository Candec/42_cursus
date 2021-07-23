#include "../includes/push_swap.h"

void	del_next(t_todo *ptr)
{
	t_todo	*tmp;

	if (ptr && ptr->next)
	{
		tmp = ptr->next->next;
		free(ptr->next);
		ptr->next = tmp;
	}
}

static int	to_del(t_todo *list)
{
	char	order;

	if (!list || !list->next)
		return (0);
	order = list->order;
	while (list->next && !is_blocking(order, list->next->order))
	{
		if (is_opposite(order, list->next->order))
		{
			del_next(list);
			return (1);
		}
		list = list->next;
	}
	return (0);
}

int	del(t_todo **list)
{
	t_todo	*cur;
	int		ret;

	ret = 0;
	if (!list)
		return (ret);
	cur = *list;
	while (to_del(*list))
	{
		ret = 1;
		cur = (*list)->next;
		free(*list);
		*list = cur;
	}
	while (cur && cur->next)
	{
		if (to_del(cur->next))
		{
			ret = 1;
			del_next(cur);
		}
		cur = cur->next;
	}
	return (ret);
}
