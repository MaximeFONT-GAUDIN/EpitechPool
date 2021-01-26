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

int my_compute_factorial_it(int nb)
{
    int ret = 1;

    if (nb == 1)
        return (1);
    if (nb < 1)
        return (0);
    for (int i = 1; i <= nb; i++) {
        ret = ret * i;
        if (ret < 0)
            return (0);
    }
    return (ret);
}

int main(void)
{
    my_put_nbr(my_compute_factorial_it(17));
    return (0);
}