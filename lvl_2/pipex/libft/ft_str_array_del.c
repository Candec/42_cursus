#include "libft.h"

void	ft_str_array_del(char ***str_array)
{
	int	i;

	i = -1;
	while ((*str_array)[++i])
		ft_strdel(&(*str_array)[i]);
	*str_array = NULL;
}
