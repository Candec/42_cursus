#include "ft_printf.h"

char	*ft_itoa_base(int_fast64_t value, int base, char *str)
{
	int				len;
	uint_fast64_t	u_value;
	char			placeholder[17];

	ft_strcpy(placeholder, "0123456789abcdef");
	len = ft_numlen(value, base);
	str = malloc(sizeof(char) * len);
	// str = ft_calloc(len, 4);
	if (value == 0)
		return (ft_strcpy(str, "0"));
	u_value = (uint_fast64_t)value;
	len--;
	while (base == 10 && value)
	{
		str[len] = placeholder[ft_abs(value % base)];
		value = value / base;
		len--;
	}
	while (base != 10 && u_value)
	{
		str[len] = placeholder[u_value % base];
		u_value = u_value / base;
		len--;
	}
	return (str);
}
