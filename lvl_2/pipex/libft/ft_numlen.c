#include "libft.h"

int	ft_numlen(int_fast64_t value, int base)
{
	int				i;
	uint_fast64_t	u_value;

	i = 0;
	u_value = (uint_fast64_t)value;
	if (value == 0)
		return (0);
	if (value < 0 && base == 10)
		i++;
	while (base == 10 && value)
	{
		value = value / base;
		i++;
	}
	while (base != 10 && u_value)
	{
		u_value = u_value / base;
		i++;
	}
	return (i);
}
