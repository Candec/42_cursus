#include "header.h"

int	ft_printf(const char *fmt, ...)
{
	unsigned int i;
	va_list arg;
	va_start(arg, fmt);
	while (*fmt != '\0')
	{
		while (*fmt != '%')
		{
			ft_putchar(*fmt);
			fmt++;
		}
		fmt++;
		switch (*fmt)
		{
		case 's':
			i = va_arg(arg, char *);
			ft_putstr(i);
			break;

		default:
			break;
		}
	}

	va_end(arg);

}


int main()
{
	char test[] = "test";
	printf("Test 1 - Strings\n");

	printf("Function: ");
	ft_printf("Esto es un %s\n", test);
	printf("Expected: ");
	printf("Esto es un %s\n", test);

	printf("======================\n");

	int num = 1;
	printf("Test 2 - Intigers\n");

	printf("Function: ");
	ft_printf("Esto es %d test\n", num);
	printf("Expected: ");
	printf("Esto es %d test\n", num);
}
