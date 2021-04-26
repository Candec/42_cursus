#include "ft_printf.h"

int	main(void)
{
	printf("\n");
	printf("test 1 - Normal Test\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n",printf("check check check me\n"));
	printf("Result:\n");
	printf("[%d]\n",ft_printf("check check check me\n"));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 2 - Single String\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n",printf("%s\n", "This is a test"));
	printf("Result:\n");
	printf("[%d]\n",ft_printf("%s\n", "This is a test"));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 3 - Multiple Strings\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n",printf("%s%s%s%s\n", "123", "456", "789", "This Was a Test"));
	printf("Result:\n");
	printf("[%d]\n",ft_printf("%s%s%s%s\n", "123", "456", "789", "This Was a Test"));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 4 - Strings & normals\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n",printf("%s%s%s %s, and it was %s test\n", "123", "456", "789", "This Was a", "good"));
	printf("Result:\n");
	printf("[%d]\n",ft_printf("%s%s%s %s, and it was %s test\n", "123", "456", "789", "This Was a", "good"));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 5 - Strings & Chars\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n",printf("%s%s%s %s, and it was %c%c%c%c test\n", "123", "456", "789", "numbers", 'g', 'o', 'o', 'd'));
	printf("Result:\n");
	printf("[%d]\n",ft_printf("%s%s%s %s, and it was %c%c%c%c test\n", "123", "456", "789", "numbers", 'g', 'o', 'o', 'd'));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 6 - String Width Greater than Var1 & Precision\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n",printf("Madonna %20.5s Madonna\n", "Incredible width"));
	printf("Result:\n");
	printf("[%d]\n",ft_printf("Madonna %20.5s Madonna\n", "Incredible width"));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 7 - String Width Lower than Var1 & Precision\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n",printf("a%-7.5sa\n", "Incredible width"));
	printf("Result:\n");
	printf("[%d]\n",ft_printf("a%-7.5sa\n", "Incredible width"));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 8 - String Width greater than Var1 & Precision\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("x%.5sx\n", "Wellcome"));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("x%.5sx\n", "Wellcome"));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 8 - String Width greater than Var1 & Precision\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("x%20.5sx\n", "Wellcome"));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("x%20.5sx\n", "Wellcome"));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 9 - String NULL\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("test %s\n", NULL));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("test %s\n", NULL));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 10 - String exact precision NULL\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("test %.7s\n", NULL));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("test %.7s\n", NULL));
	printf("\n");
	printf("\n");
	printf("\n");

	printf("test 11 - String over precision NULL\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("test %.10s\n", NULL));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("test %.10s\n", NULL));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 12 - String under precision NULL\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("%.5s\n", NULL));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("%.5s\n", NULL));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 12 - String precision 0 NULL\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("%.0s\n", "test"));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("%.0s\n", "test"));
	printf("\n");
	printf("\n");
	printf("\n");

	printf("test 13 - String precision 0 NULL with width\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("%10.0s\n", "test"));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("%10.0s\n", "test"));
	printf("\n");
	printf("\n");
	printf("\n");

	printf("test 14 - String precision 0 NULL with negative width\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("%-10.0s\n", "test"));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("%-10.0s\n", "test"));
	printf("\n");
	printf("\n");
	printf("\n");

}
