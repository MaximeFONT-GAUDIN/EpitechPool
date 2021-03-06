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

int my_is_prime(int nb)
{
    if (nb <= 1)
        return (0);
    if (nb == 2 || nb == 3)
        return (1);
    for (int i = 2; i != 4; i++) {
        if (nb % i == 0)
            return (0);
    }
    return (1);
}

int my_find_prime_sup(int nb)
{
    int ret = nb;

    for (; my_is_prime(ret) != 1; ret++);
    return (ret);
}

int main(void)
{
    my_put_nbr(my_find_prime_sup(7880));
    return (0);
}