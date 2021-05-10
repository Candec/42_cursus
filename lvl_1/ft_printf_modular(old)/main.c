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


	printf("test 6 - String Width\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n",printf("Madonna, %20s Madonna\n", "Incredible width"));
	printf("Result:\n");
	printf("[%d]\n",ft_printf("Madonna, %20s Madonna\n", "Incredible width"));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 7 - String Width Greater than Var1 & Precision\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n",printf("Madonna %20.5s Madonna\n", "Incredible width"));
	printf("Result:\n");
	printf("[%d]\n",ft_printf("Madonna %20.5s Madonna\n", "Incredible width"));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 8 - String Width Lower than Var1 & Precision\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n",printf("a%-7.5sa\n", "Incredible width"));
	printf("Result:\n");
	printf("[%d]\n",ft_printf("a%-7.5sa\n", "Incredible width"));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 9 - String Width greater than Var1 & Precision\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("x%.5sx\n", "Wellcome"));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("x%.5sx\n", "Wellcome"));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 10 - String Width greater than Var1 & Precision\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("x%20.5sx\n", "Wellcome"));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("x%20.5sx\n", "Wellcome"));
	printf("\n");
	printf("\n");
	printf("\n");

	char *null = "";
	printf("test 11 - String NULL\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("test %s\n", null));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("test %s\n", null));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 12 - String exact precision NULL\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("test %.7s\n", null));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("test %.7s\n", null));
	printf("\n");
	printf("\n");
	printf("\n");

	printf("test 13 - String over precision NULL\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("test %.10s\n", null));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("test %.10s\n", null));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 14 - String under precision NULL\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("%.5s\n", null));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("%.5s\n", null));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 15 - String precision 0 NULL\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("%.0s\n", "test"));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("%.0s\n", "test"));
	printf("\n");
	printf("\n");
	printf("\n");

	printf("test 16 - String precision 0 NULL with width\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("%10.0s\n", "test"));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("%10.0s\n", "test"));
	printf("\n");
	printf("\n");
	printf("\n");

	printf("test 17 - String precision 0 NULL with negative width\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("%-10.0s\n", "test"));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("%-10.0s\n", "test"));
	printf("\n");
	printf("\n");
	printf("\n");

	int	num = 10;
	int	*pointer = &num;
	printf("test 18 - POINTER - BASIC\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("%p\n", &num));
	printf("[%d]\n", printf("%p\n", pointer));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("%p\n", &num));
	printf("[%d]\n", ft_printf("%p\n", pointer));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 19 - POINTER - WIDTH\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("%30p\n", &num));
	printf("[%d]\n", printf("%30p\n", pointer));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("%30p\n", &num));
	printf("[%d]\n", ft_printf("%30p\n", pointer));
	printf("\n");
	printf("\n");
	printf("\n");

	printf("test 20 - POINTER - WIDTH\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("%-30px\n", &num));
	printf("[%d]\n", printf("%-30px\n", pointer));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("%-30px\n", &num));
	printf("[%d]\n", ft_printf("%-30px\n", pointer));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 21 - INTIGERS - BASIC\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("%d\n", 42));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("%d\n", 42));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 22 - INTIGERS - MAX INT\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("%d\n", INT_MAX));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("%d\n", INT_MAX));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 23 - INTIGERS - MIN INT\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("%d\n", INT_MIN));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("%d\n", INT_MIN));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 24 - INTIGERS - 0 INT\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("%d\n", 0));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("%d\n", 0));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 25 - INTIGERS - MAX INT WITH WIDTH\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("%30d\n", INT_MAX));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("%30d\n", INT_MAX));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 26 - INTIGERS - MAX INT WITH WIDTH LOWER THAN THE NUMBER LENGTH\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("%7d\n", INT_MAX));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("%7d\n", INT_MAX));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 27 - INTIGERS - MAX INT WITH PRECISION\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("%30.16d\n", INT_MAX));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("%30.16d\n", INT_MAX));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 28 - INTIGERS - MAX INT WITH PRECISION LOWER THAN THE NUMBER LENGTH\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("%25.5d\n", INT_MAX));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("%25.5d\n", INT_MAX));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 29 - INTIGERS - MAX INT WITH PRECISION OVERFLOW, WIDTH & MINUS FLAG \n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("%-25.16d\n", INT_MAX));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("%-25.16d\n", INT_MAX));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 30 - INTIGERS - PRECISION OVERFLOW, WIDTH & PLUS FLAG \n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("%+25.16d\n", 666));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("%+25.16d\n", 666));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 31 - INTIGERS - PRECISION OVERFLOW, WIDTH & PLUS FLAG & MINUS FLAG \n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("%+-25.16d\n", -777));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("%+-25.16d\n", -777));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 32 - INTIGERS - POSITIVE INTIGER WIDTH WITH 0 FLAF & PLUS FLAG \n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("%+025d\n", 666));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("%+025d\n", 666));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("test 33 - INTIGERS - NEGATIVE INTIGER WIDTH WITH 0 FLAF & PLUS FLAG \n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n", printf("%+-25d\n", -222232323));
	printf("Result:\n");
	printf("[%d]\n", ft_printf("%+-25d\n", -222232323));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("\n");
	printf("test 34 - NEGATIVE PRECISION\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n",printf("%*cxx\n", -10, '0'));
	printf("Result:\n");
	printf("[%d]\n",ft_printf("%*cxx\n", -10, '0'));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("\n");
	printf("test 35 - NULL STRING MULTI-TEST\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n",printf(" 7 %.*s ", 7, NULL));
	printf("[%d]\n",printf(" 6 %.*s ", 6, NULL));
	printf("[%d]\n",printf(" 5 %.*s ", 5, NULL));
	printf("[%d]\n",printf(" 4 %.*s ", 4, NULL));
	printf("[%d]\n",printf(" 3 %.*s ", 3, NULL));
	printf("[%d]\n",printf(" 2 %.*s ", 2, NULL));
	printf("[%d]\n",printf(" 1 %.*s ", 1, NULL));
	printf("[%d]\n",printf(" 0 %.*s ", 0, NULL));
	printf("[%d]\n",printf(" -1 %.*s ", -1, NULL));
	printf("[%d]\n",printf(" -2 %.*s ", -2, NULL));
	printf("[%d]\n",printf(" -3 %.*s ", -3, NULL));
	printf("[%d]\n",printf(" -4 %.*s ", -4, NULL));
	printf("[%d]\n",printf(" -5 %.*s ", -5, NULL));
	printf("[%d]\n",printf(" -6 %.*s ", -6, NULL));
	printf("[%d]\n",printf(" -7 %.*s ", -7, NULL));
	printf("Result:\n");
	printf("[%d]\n",ft_printf(" 7 %.*s ", 7, NULL));
	printf("[%d]\n",ft_printf(" 6 %.*s ", 6, NULL));
	printf("[%d]\n",ft_printf(" 5 %.*s ", 5, NULL));
	printf("[%d]\n",ft_printf(" 4 %.*s ", 4, NULL));
	printf("[%d]\n",ft_printf(" 3 %.*s ", 3, NULL));
	printf("[%d]\n",ft_printf(" 2 %.*s ", 2, NULL));
	printf("[%d]\n",ft_printf(" 1 %.*s ", 1, NULL));
	printf("[%d]\n",ft_printf(" 0 %.*s ", 0, NULL));
	printf("[%d]\n",ft_printf(" -1 %.*s ", -1, NULL));
	printf("[%d]\n",ft_printf(" -2 %.*s ", -2, NULL));
	printf("[%d]\n",ft_printf(" -3 %.*s ", -3, NULL));
	printf("[%d]\n",ft_printf(" -4 %.*s ", -4, NULL));
	printf("[%d]\n",ft_printf(" -5 %.*s ", -5, NULL));
	printf("[%d]\n",ft_printf(" -6 %.*s ", -6, NULL));
	printf("[%d]\n",ft_printf(" -7 %.*s ", -7, NULL));
	printf("\n");
	printf("\n");
	printf("\n");


	printf("\n");
	printf("test 36 - NEGATIVE PRECISION\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	printf("[%d]\n",printf("%*cxx\n", -10, '0'));
	printf("Result:\n");
	printf("[%d]\n",ft_printf("%*cxx\n", -10, '0'));
	printf("\n");
	printf("\n");
	printf("\n");


	// printf("\n");
	// printf("test 37 - NEGATIVE PRECISION\n");
	// printf("++++++++++++++++\n");
	// printf("\n");
	// printf("Expected:\n");
	// printf("[%d]\n",printf("%10p %-10p ", 0, 0));
	// printf("Result:\n");
	// printf("[%d]\n",ft_printf("%10p %-10p ", 0, 0));
	// printf("\n");
	// printf("\n");
	// printf("\n");


	printf("\n");
	printf("test 37 - INTIGERS\n");
	printf("++++++++++++++++\n");
	printf("\n");
	printf("Expected:\n");
	// printf( "[%d]\n", printf("\n 0*%0-*.*d*0 0*%0*.*d*0 \n", 2, 6, 102, 21, 10, -101));
	// printf( "[%d]\n", printf("\n 0*%0-*d*0 0*%0*d*0 \n", 21, 1021, 21, -1011));
	// printf( "[%d]\n", printf("\n 0*%-0*.10d*0 0*%-0*.0d*0 \n", 21, 1021, 21, -1011));
	printf( "[%d]\n", printf("\n --0*%0*.0d*0 0*%0*.10d*0-- \n", -2, 0, 21, 1));
	// printf( "[%d]\n", printf("\n --0*%0*.0d*0 0*%0*.10d*0-- \n", -21, INT_MAX, 21, INT_MIN));
	// printf( "[%d]\n", printf("\n --0*%0*.0d*0 0*%0*.10d*0-- \n", -21, LONG_MAX, 21, LONG_MIN));
	// printf( "[%d]\n", printf("\n --0*%-0*.20d*0 0*%-0*.10d*0-- \n", -21, CHAR_MAX, 21, CHAR_MIN));
	// printf( "[%d]\n", printf("\n --0*%-0*.2d*0 0*%-0*.2d*0-- \n", -21, CHAR_MAX, 21, CHAR_MIN));
	// printf( "[%d]\n", printf("\n --0*%-0*.3d*0 0* %-0*.3d*0-- \n", -21, CHAR_MAX, 21, CHAR_MIN));
	// printf( "[%d]\n", printf("\n --0*%-0*.4d*0 0* %-0*.4d*0-- \n", -21, CHAR_MAX, 21, CHAR_MIN));
	// printf( "[%d]\n", printf("\n %9.2d \n", UINT_MAX));
	printf("Result:\n");
	// printf( "[%d]\n", ft_printf("\n 0*%0-*.*d*0 0*%0*.*d*0 \n", 2, 6, 102, 21, 10, -101));
	// printf( "[%d]\n", ft_printf("\n 0*%0-*d*0 0*%0*d*0 \n", 21, 1021, 21, -1011));
	// printf( "[%d]\n", ft_printf("\n 0*%-0*.10d*0 0*%-0*.0d*0 \n", 21, 1021, 21, -1011));
	printf( "[%d]\n", ft_printf("\n --0*%0*.0d*0 0*%0*.10d*0-- \n", 2, 0, 21, 1));
	// printf( "[%d]\n", ft_printf("\n --0*%0*.0d*0 0*%0*.10d*0-- \n", -21, INT_MAX, 21, INT_MIN));
	// printf( "[%d]\n", ft_printf("\n --0*%0*.0d*0 0*%0*.10d*0-- \n", -21, LONG_MAX, 21, LONG_MIN));
	// printf( "[%d]\n", ft_printf("\n --0*%-0*.20d*0 0*%-0*.10d*0-- \n", -21, CHAR_MAX, 21, CHAR_MIN));
	// printf( "[%d]\n", ft_printf("\n --0*%-0*.2d*0 0*%-0*.2d*0-- \n", -21, CHAR_MAX, 21, CHAR_MIN));
	// printf( "[%d]\n", ft_printf("\n --0*%-0*.3d*0 0*%-0*.3d*0-- \n", -21, CHAR_MAX, 21, CHAR_MIN));
	// printf( "[%d]\n", ft_printf("\n --0*%-0*.4d*0 0*%-0*.4d*0-- \n", -21, CHAR_MAX, 21, CHAR_MIN));
	// printf( "[%d]\n", ft_printf("\n %9.2d \n", UINT_MAX));
	printf("\n");
	printf("\n");
	printf("\n");
}
