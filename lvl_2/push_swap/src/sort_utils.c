#include "push_swap.h"

int	median(t_node *pile, int size)
{
	int		bigger;
	int		lower;
	int		i;
	t_node	*cur;
	t_node	*tmp;

	cur = pile;
	bigger = 0;
	lower = 10;
	while (bigger - lower != 0 && bigger - lower != -1)
	{
		bigger = 0;
		lower = 0;
		i = -1;
		tmp = pile;
		while (++i < size)
		{
			bigger += (cur->n < tmp->n);
			lower += (cur->n > tmp->n);
			tmp = tmp->next;
		}
		cur = cur->next;
	}
	return (cur->last->n);
}

static void	swapa(t_node **a, t_node **b)
{
	do_order(RA, a, b);
	do_order(SA, a, b);
	do_order(RRA, a, b);
}

static void	swapb(t_node **a, t_node **b)
{
	do_order(RB, a, b);
	do_order(SB, a, b);
	do_order(RRB, a, b);
}

void	sort3(t_node **a, t_node **b, int until, int sorted)
{
	if ((sorted && !is_sorted(*a, until, sorted))
		|| (!sorted && !is_sorted(*b, until, sorted)))
	{
		if ((sorted && !is_sorted(*a, 2, sorted))
			|| (!sorted && !is_sorted(*b, 2, sorted)))
		{
			if (sorted)
				do_order(SA, a, b);
			else
				do_order(SB, a, b);
		}
		else
		{
			if (sorted)
				swapa(a, b);
			else
				swapb(a, b);
		}
		sort3(a, b, until, sorted);
	}
}

int	act(t_node **a, t_node **b, int sorted, int pivot)
{
	if ((sorted && (*a)->n < pivot) || (!sorted && (*b)->n >= pivot))
	{
		if (sorted)
			do_order(PB, a, b);
		else
			do_order(PA, a, b);
		return (1);
	}
	else
	{
		if (sorted)
			do_order(RA, a, b);
		else
			do_order(RB, a, b);
	}
	return (0);
}
