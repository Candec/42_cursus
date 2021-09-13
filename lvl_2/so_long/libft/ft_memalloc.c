#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)malloc(size);
	if (!ptr)
		return (NULL);
	while (ptr && i < size)
		ptr[i++] = 0;
	return ((void *)ptr);
}
