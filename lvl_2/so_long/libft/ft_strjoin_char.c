#include "libft.h"

char	*ft_strjoin_char(const char *s1, char c)
{
	char	*join;
	size_t	i;
	size_t	size;

	if (!s1)
		size = 2;
	else
		size = ft_strlen(s1) + 2;
	join = (char *)malloc(size * sizeof(char));
	if (!(join))
		return (NULL);
	i = 0;
	while (s1 && *s1)
		join[i++] = *s1++;
	join[i++] = c;
	join[i] = '\0';
	return (join);
}
