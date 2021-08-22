#include "../includes/push_swap.h"

static void	push(t_node **from, t_node **to)
{
	t_node	*tmp;

	if (!*from)
		return ;
	tmp = *from;
	tmp->last->next = tmp->next;
	tmp->next->last = tmp->last;
	if (tmp != tmp->next)
		*from = tmp->next;
	else
		*from = NULL;
	if (*to)
		tmp->next = *to;
	else
		tmp->next = tmp;
	if (*to)
		tmp->last = (*to)->last;
	else
		tmp->last = tmp;
	if (*to)
	{
		(*to)->last->next = tmp;
		(*to)->last = tmp;
	}
	*to = tmp;
}

static void	rotate(t_node **node, int reverse)
{
	if (reverse)
		*node = (*node)->last;
	else
		*node = (*node)->next;
}

static int	apply_s(char *str, t_node **a, t_node **b)
{
	int	tmp;

	if ((*str == 'a' || *str == 's') && *a)
	{
		tmp = (*a)->n;
		(*a)->n = (*a)->next->n;
		(*a)->next->n = tmp;
	}
	if ((*str == 'b' || *str == 's') && *b)
	{
		tmp = (*b)->n;
		(*b)->n = (*b)->next->n;
		(*b)->next->n = tmp;
	}
	return ((*str == 'a' || *str == 'b' || *str == 'r') && str[1] == '\0');
}

static int	apply_r(char *str, t_node **a, t_node **b)
{
	int	reverse;

	reverse = (str[0] == 'r' && str[1]);
	str += reverse;
	if ((*str == 'a' || *str == 'r') && *a)
		rotate(a, reverse);
	if ((*str == 'b' || *str == 'r') && *b)
		rotate(b, reverse);
	return ((*str == 'a' || *str == 'b' || *str == 'r') && str[1] == '\0');
}

int	apply(char *str, t_node **a, t_node **b)
{
	if (*str == '\0')
		return (1);
	if (*str == 's')
		return (apply_s(str + 1, a, b));
	else if (*str == 'p')
	{
		str++;
		if (*str == 'a')
			push(b, a);
		else if (*str == 'b')
			push (a, b);
		return (*str == 'a' || *str == 'b');
	}
	else if (*str == 'r')
		return (apply_r(str + 1, a, b));
	return (0);
}
