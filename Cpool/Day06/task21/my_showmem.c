#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}

int my_strlen(char const *str)
{
    int ret = 0;

    for (;str[ret] != 0; ret++);
    return (ret);
}

int my_putnbr_base(int nbr, char const *base)
{
    int size = my_strlen(base);
    int digit = 0;
    int rest = 0;

    if (nbr < 0) {
        my_putchar('-');
        nbr = nbr * -1;
    }
    digit = nbr % size;
    rest = (nbr - digit) / size;
    if (rest != 0) {
        my_putnbr_base(rest, base);
    }
    my_putchar(base[digit]);
    return (0);
}

int my_char_isprintable(char c)
{
    if (c < 32 || c > 126)
        return (0);
    return (1);
}

void my_modified_putstr(char *str, int n)
{
    for (int i = 0; i != n; i++) {
        if (my_char_isprintable(str[i]) == 1)
            my_putchar(str[i]);
        else
            my_putchar('.');
    }
}

void my_print_hexa(char const *str, int n)
{
    for (int i = 0; i != n; i++) {
        if (str[i] < 16) {
            my_putchar('0');
            my_putnbr_base(str[i], "0123456789abcdef");
        }
        else
            my_putnbr_base(str[i], "0123456789abcdef");
        if (i % 2 != 0)
            my_putchar(' ');
    }
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int src_size = my_strlen(src);

    for (int i = 0; i != n; i++)
        dest[i] = 0;
    if (src_size < n) {
        for (int i = 0; src[i] != 0; i++) {
            dest[i] = src[i];
        }
        for (; src_size != n; src_size++) {
            dest[src_size] = 0;
        }
    }
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
    return (dest);
}

int my_compute_power_it(int nb, int p)
{
    int ret = 1;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    for (int i = 0; i != p; i++) {
        ret *= nb;
    }
    return (ret);
}

int n_power(int nbr, int base)
{
    int power = 1;

    for (int i = 0; i != 7; i++)
        if (my_compute_power_it(16, i) == nbr)
            power = 2;
    for (; nbr > my_compute_power_it(base, power); power++);
    return (power);
}

int my_showmeme(char const *str, int size)
{
    int line = 0;
    char save_str[16];

    if (size % 16 != 0)
        line = (size / 16) + 1;
    else
        line = size / 16;
    for (int i = 0; i != line; i++) {
        my_strncpy(save_str, str + (i * 16), 16);
        // print first part of the line
        for (int j = 0; j != 7 - n_power(i, 16); j++) {
            my_putchar('0');
        }
        if (i == 0)
            my_putchar('0');
        my_putnbr_base(i * 16, "0123456789abcdef");
        my_modified_putstr(": ", 2);
        // print second part of the line
        if (i * 16 <= size - 16)
            my_print_hexa(save_str, 16);
        else {
            my_print_hexa(save_str, (size - (i * 16)));
            for (int j = 0; j != (16 - (size - (i * 16))); j++) {
                if (j % 2 != 0)
                    my_putchar(' ');
                my_putchar(' ');
                my_putchar(' ');
            }
            if (size % 2 != 0)
                my_putchar(' ');
        }
        // print third part of the line
        if (i * 16 <= size - 16)
            my_modified_putstr(save_str, 16);
        else
            my_modified_putstr(save_str, (size - (i * 16)));
        my_putchar('\n');
    }
    return (0);
}

int main(void)
{
    char const str[] = "bonjour je suis une phrase de test et je suis volontairement tres longuemais c est pas pour faire chier c est juste que ca va faciliter vachement les tests";

    my_showmeme(str, 257);
    return (0);
}