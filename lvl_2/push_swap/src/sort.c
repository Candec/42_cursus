#include "push_swap.h"



// void	sort(t_stacks stacks, int size)
// {
// 	int		i;
// 	int		reset;
// 	// int		pivot;
// 	bool	sorted;

// 	i = 0;
// 	reset = 0;
// 	sorted = false;
// 	if (is_sorted(sorted, size))
//     {
//         printf("it is sorted");
// 		return ;
//     }
// }
// static int		is_sorted(t_node *pile, int until, int apile)
// {
// 	return (ksorted(pile, apile) >= until);
// }


//-------------------------------------------------------------------


// int				median(t_node *pile, int size)
// {
// 	int		bigger;
// 	int		lower;
// 	int		i;
// 	t_node	*cur;
// 	t_node	*tmp;

// 	cur = pile;
// 	bigger = 0;
// 	lower = 10;
// 	while (bigger - lower != 0 && bigger - lower != -1)
// 	{
// 		bigger = 0;
// 		lower = 0;
// 		i = -1;
// 		tmp = pile;
// 		while (++i < size)
// 		{
// 			bigger += (cur->n < tmp->n);
// 			lower += (cur->n > tmp->n);
// 			tmp = tmp->next;
// 		}
// 		cur = cur->next;
// 	}
// 	return (cur->last->n);
// }

// void			sort3(t_node **a, t_node **b, int until, int apile)
// {
// 	if (!is_sorted((apile) ? *a : *b, until))
// 	{
// 		if (!is_sorted((apile) ? *a : *b, 2))
// 			do_order((apile) ? SA : SB, a, b);
// 		else
// 		{
// 			do_order((apile) ? RA : RB, a, b);
// 			do_order((apile) ? SA : SB, a, b);
// 			do_order((apile) ? RRA : RRB, a, b);
// 		}
// 		sort3(a, b, until, apile);
// 	}
// }

// int				act(t_node **a, t_node **b, int apile, int pivot)
// {
// 	if ((apile && (*a)->n < pivot) || (!apile && (*b)->n >= pivot))
// 	{
// 		do_order((apile) ? PB : PA, a, b);
// 		return (1);
// 	}
// 	else
// 		do_order((apile) ? RA : RB, a, b);
// 	return (0);
// }

// void			quicksort(t_stacks p, int until, int apile, int fiter)
// {
// 	int		i;
// 	int		reset;
// 	int		pivot;

// 	i = 0;
// 	reset = 0;
// 	pivot = median((apile) ? *(p.a) : *(p.b), until);
// 	if (is_sorted((apile) ? *(p.a) : *(p.b), until))
// 		return ;
// 	while (until > 3 && i < (until / 2) + (until % 2 && !apile) && ++reset)
// 		i += act(p.a, p.b, apile, pivot);
// 	while ((!fiter) && (reset--) - i)
// 		do_order((apile) ? RRA : RRB, p.a, p.b);
// 	if (i && !apile)
// 		quicksort(p, i, !apile, 0);
// 	if (until - i <= 3)
// 		sort3(p.a, p.b, until - i, apile);
// 	else
// 		quicksort(p, until - i, apile, (fiter == 2) ? fiter - 1 : fiter);
// 	if (i && apile)
// 		quicksort(p, i, !apile, (fiter == 2) ? 1 : 0);
// 	while (i--)
// 		do_order(apile ? PA : PB, p.a, p.b);
// }


int				median(t_node *pile, int size)
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

void			sort3(t_node **a, t_node **b, int until, int apile)
{
	if (!is_sorted((apile) ? *a : *b, until))
	{
		if (!is_sorted((apile) ? *a : *b, 2))
			do_order((apile) ? SA : SB, a, b);
		else
		{
			do_order((apile) ? RA : RB, a, b);
			do_order((apile) ? SA : SB, a, b);
			do_order((apile) ? RRA : RRB, a, b);
		}
		sort3(a, b, until, apile);
	}
}

int				act(t_node **a, t_node **b, int apile, int pivot)
{
	if ((apile && (*a)->n < pivot) || (!apile && (*b)->n >= pivot))
	{
		do_order((apile) ? PB : PA, a, b);
		return (1);
	}
	else
		do_order((apile) ? RA : RB, a, b);
	return (0);
}

void			quicksort(t_stacks p, int until, int apile, int fiter)
{
	int		i;
	int		reset;
	int		pivot;

	i = 0;
	reset = 0;
	pivot = median((apile) ? *(p.a) : *(p.b), until);
	if (is_sorted((apile) ? *(p.a) : *(p.b), until))
		return ;
	while (until > 3 && i < (until / 2) + (until % 2 && !apile) && ++reset)
		i += act(p.a, p.b, apile, pivot);
	while ((!fiter) && (reset--) - i)
		do_order((apile) ? RRA : RRB, p.a, p.b);
	if (i && !apile)
		quicksort(p, i, !apile, 0);
	if (until - i <= 3)
		sort3(p.a, p.b, until - i, apile);
	else
		quicksort(p, until - i, apile, (fiter == 2) ? fiter - 1 : fiter);
	if (i && apile)
		quicksort(p, i, !apile, (fiter == 2) ? 1 : 0);
	while (i--)
		do_order(apile ? PA : PB, p.a, p.b);
}