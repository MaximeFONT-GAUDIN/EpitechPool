#include <unistd.h>
#include <stdlib.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else 
        my_putchar('P');
    return (0);
}

int main (int ac, char **av)
{
    if (av[1] != NULL) {
        my_isneg(atoi(av[1]));
        return (0);
    }
    return (1);
}