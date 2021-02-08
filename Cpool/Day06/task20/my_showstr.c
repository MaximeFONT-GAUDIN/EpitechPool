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

int my_showstr(char const *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] < 32) {
            my_putchar('\\');
            if (str[i] < 16)
                my_putchar('0');
            my_putnbr_base(str[i], "0123456789abcdef");
            continue;
        }
        my_putchar(str[i]);
    }
    return (0);
}

int main(void)
{
    my_showstr("\n ponies!");
    return (0);
}