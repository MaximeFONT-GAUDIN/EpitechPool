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

int find_min(int n)
{
    int ret = 0;
    int digit = 1;
    for (; n != 1; n--) {
        ret += (n - 1) * digit;
        digit *= 10;
    }
    return (ret);
}

int find_max(int n)
{
    int ret = 9;
    int tmp = 8;
    int digit = 10;

    for (; n != 1; n--) {
        ret += (tmp) * digit;
        digit *= 10;
        tmp--;
    }
    return (ret);
}

int nbr_verifier(int n)
{
    int tmp = n % 10;

    n /= 10;
    for (; n != 0; n = n / 10) {
        if (tmp <= n % 10) {
            return (1);
        }
        tmp = n % 10;
    }
    return (0);
}

int my_print_combn(int n)
{
    int min = find_min(n);
    int max = find_max(n);

    for (; min != max; min++) {
        if (nbr_verifier(min) == 0) {
            if (min < 100)
                my_putchar('0');
            my_put_nbr(min);
            my_putchar('\n');
        }
    }
    my_put_nbr(max);
    my_putchar('\n');
    return (0);
}

int main(void)
{
    my_print_combn(4);
    return (0);
}