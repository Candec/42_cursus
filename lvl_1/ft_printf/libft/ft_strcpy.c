char	*ft_strcpy(char *dest, char const *src, int start, int last)
{
	int	i;

	i = 0;
	while (start < last)
	{
		dest[i] = src[start];
		i++;
		start++;
	}
	dest[i] = 0;
	return (dest);
}
