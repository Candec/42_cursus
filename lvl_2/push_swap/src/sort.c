#include "push_swap.h"

void	next_quicksort(t_stacks p, int until, int sorted, int fiter)
{
	if (fiter == 2)
		quicksort(p, until, sorted, fiter - 1);
	else
		quicksort(p, until, sorted, fiter);
}

void	quicksort(t_stacks p, int until, int sorted, int fiter)
{
	int	i;
	int	reset;
	int	pivot;

	i = 0;
	reset = 0;
	pivot = get_median(sorted, p, until);
	if (get_sorted(sorted, p, until))
		return ;
	while (until > 3 && i < (until / 2) + (until % 2 && !sorted) && ++reset)
		i += act(p.a, p.b, sorted, pivot);
	while ((!fiter) && (reset--) - i)
		RRARRB(sorted, p);
	if (i && !sorted)
		quicksort(p, i, !sorted, 0);
	if (until - i <= 3)
		sort3(p.a, p.b, until - i, sorted);
	else
		next_quicksort(p, until - i, sorted, fiter);
	fitest(i, sorted, p, fiter);
	inverter(i, sorted, p);
}
