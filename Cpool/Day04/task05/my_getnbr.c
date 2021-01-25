#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
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

int my_getnbr(char *str)
{
    int nb = 0;
    long int n = 0;

    for (int i = 0; str[i] != 0; ++i) {
        if (str[i] == '-')
            nb++;
        if (str[i] >= '0' && str[i] <= '9')
            n = n * 10 + (str[i] - '0');
        else if (str[i] >= 'a' && str[i] <= 'z')
            break;
        if (n > 2147483647 && nb % 2 != 1)
            return (0);
        else if (n > 2147483648 && nb % 2 == 1)
            return (0);
    }
    if (nb % 2 == 1)
        return (n * (-1));
    return (n);
}

int main(void)
{
    char nbr[9] = "--12345";

    my_put_nbr(my_getnbr(nbr));
    return (0);
}