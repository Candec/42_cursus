#include "ft_printf.h"

int	main(void)
{
	printf("\n");
	printf("test 1 - Normal Test\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("check check check me\n");
	printf("Result:\n");
	ft_printf("check check check me\n");
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 2 - Single String\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("%s\n", "This is a test");
	printf("Result:\n");
	ft_printf("%s\n", "This is a test");
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 3 - Multiple Strings\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("%s%s%s%s\n", "123", "456", "789", "This Was a Test");
	printf("Result:\n");
	ft_printf("%s%s%s%s\n", "123", "456", "789", "This Was a Test");
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 4 - Strings & normals\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("%s%s%s %s, and it was %s test\n", "123", "456", "789", "This Was a", "good");
	printf("Result:\n");
	ft_printf("%s%s%s %s, and it was %s test\n", "123", "456", "789", "This Was a", "good");
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 5 - Strings & Chars\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("%s%s%s %s, and it was %c%c%c%c test\n", "123", "456", "789", "numbers", 'g', 'o', 'o', 'd');
	printf("Result:\n");
	ft_printf("%s%s%s %s, and it was %c%c%c%c test\n", "123", "456", "789", "numbers", 'g', 'o', 'o', 'd');
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 6 - String Width Greater than Var1 & Precision\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("Madonna %20.5s Madonna\n", "Incredible width");
	printf("Result:\n");
	ft_printf("Madonna %20.5s Madonna\n", "Incredible width");
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 7 - String Width Lower than Var1 & Precision\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("Madonna %-7.5s Madonna\n", "Incredible width");
	printf("Result:\n");
	ft_printf("Madonna %-7.5s Madonna\n", "Incredible width");
	printf("\n");
	printf("\n");
	printf("\n");

}
