#include "../includes/push_swap.h"

static int	add(t_node **node, int n)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (!node || !tmp)
		return (0);
	tmp->n = n;
	if (!*node)
	{
		*node = tmp;
		tmp->next = tmp;
		tmp->last = tmp;
	}
	else
	{
		tmp->next = *node;
		tmp->last = (*node)->last;
		(*node)->last->next = tmp;
		(*node)->last = tmp;
	}
	return (1);
}

static int	check_n_atoi(char *str, int *n)
{
	int		i;
	int		sign;
	long	tmp;

	i = 0;
	tmp = 0;
	sign = 1;
	if (str[0] == '-')
		sign = -1;
	i += (str[0] == '-' || str[0] == '+');
	while (ft_isdigit(str[i]))
	{
		tmp = tmp * 10 + (sign * (str[i++] - '0'));
		if (tmp < INT_MIN || tmp > INT_MAX)
			return (0);
	}
	*n = (int)tmp;
	return (1);
}

static int	split_atoi(char *str, t_node **node, int check)
{
	t_node		*cur;
	int			tmp;
	int			i;

	i = 0;
	while (check && str[i])
	{
		if (ft_strchr("0123456789-+", str[i]) && str[i + 1] != 'v')
		{
			check = check && check_n_atoi(str + i, &tmp);
			check = check && add(node, tmp);
			cur = *node;
			while (check && cur != (*node)->last)
			{
				check = check && !(cur->n == (*node)->last->n);
				cur = cur->next;
			}
			i += (str[i] == '-' || str[i] == '+');
			while (check && str[i] && ft_isdigit(str[i]))
				i++;
		}
		else
			i++;
	}
	return (check);
}

int	parse(char *str, t_node **node, int *err)
{
	size_t	i;

	*err = -1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	*err = (str[i] == '-' && str[i + 1] == 'v' && !ft_isdigit(str[i + 2]));
	i += *err * 2;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_isspace(str[i]))
			if (!ft_strchr("+-", str[i]))
				if (!ft_isdigit(str[i - 1]) && ft_isdigit(str[i + 1]))
					return (-1);
		i++;
	}
	if (!split_atoi(str, node, 1))
		return (-1);
	return (*node != NULL);
}
