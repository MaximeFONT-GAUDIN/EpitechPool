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

int my_char_is_letter(char c)
{
    if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
        return (1);
    return (0);
}

int my_char_is_nbr(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

char my_charupcase(char c)
{
    if (c >= 97 && c <= 122)
        return (c - 32);
    return (c);
}

char *my_strcapitalize(char *str)
{
    if (str[0] >= 97 && str[0] <= 122)
        str[0] = str[0] - 32;
    for (int i = 1; str[i] != 0; i++)
        if (my_char_is_letter(str[i - 1]) == 0 && my_char_is_nbr(str[i - 1]) == 0)
            str[i] = my_charupcase(str[i]);
    return (str);
}

int main(void)
{
    char str[] = "bonjour je suis une phrase avec des caracteres en majuscule 42mais -pas +tous";

    my_putstr(my_strcapitalize(str));
    return (0);
}