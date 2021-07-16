#include "libft.h"

int	ft_isnumber(char *str)
{
	// int i;

	// i = 0;
	while(*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
