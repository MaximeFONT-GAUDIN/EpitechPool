#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}

int my_print_revalpha(void)
{
    for (int i = 'z'; i != ('a' - 1); i--)
        my_putchar(i);
    return (0);
}

int main(void)
{
    my_print_revalpha();
    return (0);
}