#include "push_swap.h"

static char	last_end(t_node *node)
{
	t_node	*cur;
	int		last;

	last = node->last->n;
	cur = node;
	if (cur->n < cur->next->n && cur->next->n > cur->last->n)
		return (RRA);
	else if (cur->n > last || cur->next->n > last)
	{
		if (cur->n > last)
			return (RA);
		else if (cur->n < last)
			return (RRA);
	}
	return (0);
}

void	small_sort(t_stacks stacks)
{
	t_node	*cur;
	char	order;

	cur = *(stacks.a);
	order = last_end(cur);
	if (order)
		do_order(order, stacks.a, stacks.b);
	cur = *(stacks.a);
	if (cur->n > cur->next->n)
		do_order(SA, stacks.a, stacks.b);
}
