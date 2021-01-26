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

int my_compute_factorial_rec(int nb)
{
    int ret;

    if (nb < 0 || nb > 13)
        return (0);
    if (nb == 1)
        return (1);
    ret = nb * my_compute_factorial_rec(nb - 1);
}

int main(void)
{
    my_put_nbr(my_compute_factorial_rec(13));
    return (0);
}