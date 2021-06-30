#include "libft.h"

int	ft_isnumber(char *str)
{
	int i;

	i = 0;
	while(str[i++])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}
