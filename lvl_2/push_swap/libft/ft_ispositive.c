#include "libft.h"

ssize_t	ft_ispositive(int n)
{
	ssize_t	sign;

	sign = 1;
	if (n < 0)
		return (sign *= -1);
	return (sign);
}
