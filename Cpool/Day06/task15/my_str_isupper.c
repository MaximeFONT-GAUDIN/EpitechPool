#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
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

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] < 65 || str[i] > 90)
            return (0);
    }
    return (1);
}

int main(void)
{
    char const str[] = "UNIQUEMENTUPPERCASE";

    my_put_nbr(my_str_isupper(str));
    return (0);
}