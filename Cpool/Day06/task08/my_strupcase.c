#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    if (str == 0)
        return;
    for (int i = 0; str[i] != 0; i++)
        my_putchar(str[i]);
}

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] < 97 || str[i] > 122)
            continue;
        str[i] = str[i] - 32;
    }
    return (str);
}

int main(void)
{
    char str[] = "Je sUis uNe phrase";
    my_putstr(my_strupcase(str));
    return (0);
}