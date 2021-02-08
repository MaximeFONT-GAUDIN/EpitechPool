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

int my_strlen(char const *str)
{
    int i = 0;

    for(; str[i] != 0; i++);
    return (i);
}

char *my_strstr(char *str, char const *to_find)
{
    int same = 0;

    for (; str != 0; str++) {
        if (my_strlen(to_find) > my_strlen(str))
            return ("");
        for (int i = 0; to_find[i] != 0; i++) {
            if (str[i] == to_find[i])
                same = 1;
            else if (str[i] != to_find[i])
                same = 0;
            if (same == 0)
                break;
            if (to_find[i + 1] == 0)
                return (str);
        }
    }
    return ("");
}

int main(void)
{
    my_putstr(my_strstr("je suis une phrase", "ui"));
    return(0);
}