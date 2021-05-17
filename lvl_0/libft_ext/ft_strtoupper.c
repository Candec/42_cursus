#include "libft.h"

void	ft_strtoupper(char *str)
{
	while (str && *str)
	{
		*str = ft_toupper(*str);
		str++;
	}
}
