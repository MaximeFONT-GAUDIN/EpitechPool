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

int my_strlen(char const *str)
{
    int i = 0;
    
    for (; str[i] != 0; i++);
    return (i);
}

void my_swap(char *a, char *b)
{
    char c;

    c = *a;
    *a = *b;
    *b = c;
}

char *my_evil_str(char *str)
{
    int size = my_strlen(str) - 1;

    for (int j = 0; j < size; j++, size--) {
        my_swap(&str[j], &str[size]);
    }
    return (str);
}

int main(void)
{
    char str[8] = "abcdefgh";

    my_putstr(my_evil_str(str));
    return (0);
}