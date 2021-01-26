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

int my_compute_power_rec(int nb, int p)
{
    int ret = nb;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    if (p != 0)
        ret *= my_compute_power_rec(nb, p - 1);
    return (ret);
}

int main(void)
{
    my_put_nbr(my_compute_power_rec(5, 3));
    return (0);
}