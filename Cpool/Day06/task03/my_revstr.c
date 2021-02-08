#include <unistd.h>
#include <stdlib.h>

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
    int ret = 0;

    for (; str[ret] != 0; ret++);
    return (ret);
}

char *my_strcpy(char *dest, char *src)
{
    for (int i = 0; src[i] != 0; i++) {
        dest[i] = src[i];
    }
    dest[my_strlen(src)] = 0;
    return (dest);
}

char *my_revstr(char *str)
{
    char *save = malloc(sizeof(char) * my_strlen(str) + 1);
    int ite = 0;

    save = my_strcpy(save, str);
    for (int i = my_strlen(save) - 1; i > -1; i--, ite++) {
        str[ite] = save[i];
    }
    str[my_strlen(save)] = 0;
    return (str);
}

int main(void)
{
    char src[12] = "salut ca va";

    my_revstr(src);
    my_putstr(src);
    return (0);
}