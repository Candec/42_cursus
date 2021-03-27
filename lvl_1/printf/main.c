#include "ft_printf.h"

int main()
{
	char test[] = "test";
	char t = 't';
	printf("Test 1 - Strings\n");
	printf("Function:\n");

	ft_printf("Esto es un %c\n", t);
	printf("Expected: ");
	printf("Esto es un %s\n", test);

	// printf("======================\n");

	// int num = 1;
	// printf("Test 2 - Intigers\n");

	// printf("Function: ");
	// ft_printf("Esto es %d test\n", num);
	// printf("Expected: ");
	// printf("Esto es %d test\n", num);
}
