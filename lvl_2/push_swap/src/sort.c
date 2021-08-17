#include "push_swap.h"

static int	get_median(int sorted, t_stacks p, int until)
{
	if (sorted)
		return (median(*(p.a), until));
	else
		return (median(*(p.b), until));
}

static void	RRARRB(int sorted, t_stacks p)
{
	if (sorted)
		do_order(RRA, p.a, p.b);
	else
		do_order(RRB, p.a, p.b);
}

static void	fitest(int i, int sorted, t_stacks p, int fiter)
{
	if (i && sorted)
	{
		if (fiter == 2)
			quicksort(p, i, !sorted, 1);
		else
			quicksort(p, i, !sorted, 0);
	}
}

static void	inverter(int i, int sorted, t_stacks p)
{
	while (i--)
	{
		if (sorted)
			do_order(PA, p.a, p.b);
		else
			do_order(PB, p.a, p.b);
	}
}

bool    get_sorted(int sorted, t_stacks p, int until)
{
	if (sorted)
		return (is_sorted(*(p.a), until, sorted));
	else
		return (is_sorted(*(p.b), until, sorted));

}

void	quicksort(t_stacks p, int until, int sorted, int fiter)
{
	int	i;
	int	reset;
	int	pivot;

	i = 0;
	reset = 0;
	pivot = get_median(sorted, p, until);
	// if ((sorted && is_sorted(*(p.a), until, sorted))
	// 	|| (!sorted && is_sorted(*(p.b), until, sorted)))
	if (get_sorted(sorted, p, until))
		return ;
	while (until > 3 && i < (until / 2) + (until % 2 && !sorted) && ++reset)
		i += act(p.a, p.b, sorted, pivot);
	while ((!fiter) && (reset--) - i)
		RRARRB(sorted, p);
	if (i && !sorted)
		quicksort(p, i, !sorted, 0);
	if (until - i > 3 && fiter == 2)
		quicksort(p, until - i, sorted, fiter - 1);
	else if (until - i > 3 && fiter != 2)
		quicksort(p, until - i, sorted, fiter);
	else
		sort3(p.a, p.b, until - i, sorted);
	fitest(i, sorted, p, fiter);
	inverter(i, sorted, p);
}
