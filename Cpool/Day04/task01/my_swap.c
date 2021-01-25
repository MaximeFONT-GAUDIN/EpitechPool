#include <unistd.h>

void my_putchar(char c)
{
    write (1, &c, 1);
}

void my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}

int main(void)
{
    int a = '0';
    int b = '1';

    my_putchar(a);
    my_putchar(b);
    my_swap(&a, &b);
    my_putchar('\n');
    my_putchar(a);
    my_putchar(b);
    my_putchar('\n');
    return (0);
}