#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    if (str == 0)
        return;
    for (int i = 0; str[i] != 0; i++)
        my_putchar(str[i]);
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

int my_strlen(char *str)
{
    int ret = 0;

    for (; str[ret] != 0; ret++);
    return (ret);
}

char *my_strncpy(char *dest, char *src, int n)
{
    int src_size = my_strlen(src);

    if (src_size < n) {
        for (int i = 0; src[i] != 0; i++) {
            dest[i] = src[i];
        }
        for (; src_size != n; src_size++) {
            dest[src_size] = 0;
        }
    }
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
    return (dest);
}

int main(void)
{
    char src[12] = "salut ca va";
    char dest[17] = "";

    my_putstr("src : [");
    my_putstr(src);
    my_putstr("]\n");
    my_putstr("dest : [");
    my_putstr(dest);
    my_putstr("]\n");
    my_strncpy(dest, src, 17);
    my_putstr("src : [");
    my_putstr(src);
    my_putstr("]\n");
    my_putstr("dest : [");
    my_putstr(dest);
    my_putstr("]\n");
    return (0);
}