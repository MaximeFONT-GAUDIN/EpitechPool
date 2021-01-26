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

int main(void)
{
    my_put_nbr(my_compute_power_it(5, 3));
    return (0);
}