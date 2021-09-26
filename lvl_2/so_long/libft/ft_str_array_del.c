#include "libft.h"

void	ft_str_array_del(char **str_arr)
{
	while (str_arr++)
		ft_strdel(str_arr);
	*str_arr = NULL;
}