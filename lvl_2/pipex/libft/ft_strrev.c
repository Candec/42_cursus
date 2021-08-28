#include "libft.h"

char	*ft_strrev(char *s1)
{
	char	swp;
	int		i;
	int		len;

	i = -1;
	len = ft_strlen(s1);
	while (++i < len / 2)
	{
		swp = s1[i];
		s1[i] = s1[len - i - 1];
		s1[len - i - 1] = swp;
	}
	return (s1);
}
