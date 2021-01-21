#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}

int my_print_digits(void)
{
    for (int i = '0'; i != ('9' + 1); i++)
        my_putchar(i);
    return (0);
}

int main(void)
{
    my_print_digits();
    return (0);
}