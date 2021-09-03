#include "libft.h"

void	ft_str_array_del(char ***str_arr)
{
	int	i;

	i = -1;
	while ((*str_arr)[++i])
		ft_strdel(&(*str_arr)[i]);
	free(*str_arr);
	*str_arr = NULL;
}
