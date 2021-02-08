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

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] != 0; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return (0);
}

int main(void)
{
    my_put_nbr(my_strcmp("alut", "blut"));
    return (0);
}