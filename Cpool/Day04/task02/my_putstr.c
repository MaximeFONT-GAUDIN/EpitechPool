#include <unistd.h>

void my_putchar(char c)
{
    write (1, &c, 1);
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != 0; i++)
        my_putchar(str[i]);
    return (0);
}

int main(void)
{
    my_putstr("je refais toutes les piscines.\n");
    return (0);
}