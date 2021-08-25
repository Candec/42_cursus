#include "push_swap.h"

int	get_median(int sorted, t_stacks p, int until)
{
	if (sorted)
		return (median(*(p.a), until));
	else
		return (median(*(p.b), until));
}

void	RRARRB(int sorted, t_stacks p)
{
	if (sorted)
		do_order(RRA, p.a, p.b);
	else
		do_order(RRB, p.a, p.b);
}

void	fitest(int i, int sorted, t_stacks p, int fiter)
{
	if (i && sorted)
	{
		if (fiter == 2)
			quicksort(p, i, !sorted, 1);
		else
			quicksort(p, i, !sorted, 0);
	}
}

void	inverter(int i, int sorted, t_stacks p)
{
	while (i--)
	{
		if (sorted)
			do_order(PA, p.a, p.b);
		else
			do_order(PB, p.a, p.b);
	}
}

bool	get_sorted(int sorted, t_stacks p, int until)
{
	if (sorted)
		return (is_sorted(*(p.a), until, sorted));
	else
		return (is_sorted(*(p.b), until, sorted));
}
