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

int my_strlen(char *str)
{
    int i = 0;
    for (; str[i] != 0; i++);
    return (i);
}

char *my_strcpy(char *dest, char *src)
{
    for (int i = 0; src[i] != 0; i++)
        dest[i] = src[i];
    dest[my_strlen(src)] = 0;
    return (dest);
}

int main(void)
{
    char src[12] = "salut ca va";
    char dest[12] = "";

    my_putstr("src : [");
    my_putstr(src);
    my_putstr("]\n");
    my_putstr("dest : [");
    my_putstr(dest);
    my_putstr("]\n");
    my_strcpy(dest, src);
    my_putstr("src : [");
    my_putstr(src);
    my_putstr("]\n");
    my_putstr("dest : [");
    my_putstr(dest);
    my_putstr("]\n");
    return (0);
}