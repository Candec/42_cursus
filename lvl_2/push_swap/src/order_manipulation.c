#include "push_swap.h"

void	add_order(t_todo **todo, char order)
{
	t_todo	*new;
	t_todo	*cur;

	new = malloc(sizeof(t_todo));
	if (todo && new)
	{
		new->next = NULL;
		new->prec = NULL;
		new->order = order;
		new->invert = invert(order);
		cur = *todo;
		if (!cur)
			*todo = new;
		else
		{
			while (cur->next)
				cur = cur->next;
			new->prec = cur;
			cur->next = new;
		}
	}
}

char	invert(char order)
{
	int	ref;

	ref = 0;
	while (!is_opposite(order, ref))
		ref++;
	return (ref);
}

int	is_opposite(char order, char ref)
{
	char	tmp;

	if (order > ref)
	{
		tmp = order;
		order = ref;
		ref = tmp;
	}
	if (order <= PB && ref <= PB)
		return (order != ref);
	else if (order <= SB && ref == SB)
		return (1);
	else if ((order == RA && ref == RRA) || (order == RB && ref == RRB))
		return (1);
	return (0);
}