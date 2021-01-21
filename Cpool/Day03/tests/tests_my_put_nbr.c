#include <unistd.h>
#include "../task07/my_put_nbr.c"

int my_put_nbr(int nb);
// void my_putchar(char c);

int main(void)
{
    my_put_nbr(42);
    my_putchar('\n');
    my_put_nbr(-42);
    my_putchar('\n');
    my_put_nbr(2147483647);
    my_putchar('\n');
    my_put_nbr(-2147483647);
    my_putchar('\n');
    my_put_nbr(0);
    my_putchar('\n');
    return (0);
}