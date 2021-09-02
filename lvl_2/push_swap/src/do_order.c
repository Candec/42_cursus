#include "push_swap.h"

void	do_order(char order, t_node **a, t_node **b)
{
	t_todo	**list;

	list = get_list();
	add_order(list, order);
	apply(str_order(order), a, b);
}

char	*str_order(char order)
{
	if (order == PA)
		return ("pa\n");
	else if (order == PB)
		return ("pb\n");
	else if (order == SA)
		return ("sa\n");
	else if (order == SB)
		return ("sb\n");
	else if (order == SS)
		return ("ss\n");
	else if (order == RA)
		return ("ra\n");
	else if (order == RB)
		return ("rb\n");
	else if (order == RR)
		return ("rr\n");
	else if (order == RRA)
		return ("rra\n");
	else if (order == RRB)
		return ("rrb\n");
	else if (order == RRR)
		return ("rrr\n");
	else
		return ("ERROR\n");
}

t_todo	**get_list(void)
{
	static t_todo	*list = NULL;

	return (&list);
}

int	continuation(int i, char *buf)
{
	if (i > 2043)
	{
		ft_putstr(buf);
		i = 0;
	}
	return (i);
}

void	print_orders(void)
{
	t_todo	**list;
	t_todo	*cur;
	char	buf[2048];
	char	*str;
	int		i;

	list = get_list();
	cur = *list;
	i = 0;
	while (cur)
	{
		i = continuation(i, buf);
		str = str_order(cur->order);
		if (cur->next && (cur->order == SA && cur->next->order == SB))
		{
			str = str_order(SS);
			cur = cur->next;
		}
		ft_strcpy(buf + i, str);
		i += ft_strlen(str);
		cur = cur->next;
	}
	ft_putstr(buf);
	del_orders(list);
}
