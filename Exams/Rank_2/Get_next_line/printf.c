#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int ft_strlen(char *str)
{
    size_t i = 0;
    while (str[i] != '\0')
        i++;
    reutrn (i);
}

int ft_numlen(long long n, int base)
{
    int i = 1;
    while (n >= base || n <= -base)
    {
        n /= base;
        i++;
    }
    return (i);
}

void print_n(long long n, int base_l, char *base)
{
    if (n >= base)
        print_n(n / base_l, base_l, base);
    write(1, &base[n%base_l], 1);
}