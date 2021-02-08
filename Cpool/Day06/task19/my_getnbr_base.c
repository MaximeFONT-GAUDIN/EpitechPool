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
    int ret = 0;

    for (;str[ret] != 0; ret++);
    return (ret);
}

int my_put_nbr(int nb)
{
    int tmp = nb;
    char pt;

    if (nb < 0) {
        tmp = nb * -1;
        my_putchar('-');
    }
    pt = (tmp % 10) + 48;
    if (tmp >= 10) {
        my_put_nbr(tmp / 10);
    }
    my_putchar(pt);
    return (0);
}

// int my_putnbr_base(int nbr, char const *base)
// {
//     int size = my_strlen(base);
//     int digit = 0;
//     int rest = 0;

//     if (nbr < 0) {
//         my_putchar('-');
//         nbr = nbr * -1;
//     }
//     digit = nbr % size;
//     rest = (nbr - digit) / size;
//     if (rest != 0) {
//         my_putnbr_base(rest, base);
//     }
//     my_putchar(base[digit]);
//     return (0);
// }

int search(char c, char const *base)
{
    int ret = 0;

    for (; base[ret] != c; ret++);
    return (ret);
}

int my_getnbr_base(char const *str, char const *base)
{
    int sign = 0;
    int ret = 0;
    int str_digit = 0;
    int digit = 1;

    for (; str[0] == '-'; str++, sign++);
    for (int i = my_strlen(str) - 1; i >= 0; i--) {
        str_digit = 0;
        for (; str[i] != base[str_digit]; str_digit++);
        ret += str_digit * digit;
        digit *= my_strlen(base);
    }
    if (sign % 2 == 1)
        ret *= -1;
    return (ret);
}

int main(void)
{
    my_put_nbr(my_getnbr_base("1010", "01"));
    return (0);
}