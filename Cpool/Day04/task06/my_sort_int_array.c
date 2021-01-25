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

void my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}

void my_sort_int_array(int *array, int size)
{
    for (int i = 1; i != size; i++) {
        if (array[i] < array[i - 1]) {
            my_swap(&array[i], &array[i - 1]);
            i = 1;
        }
    }
    for (int i = 1; i != size; i++) {
        if (array[i] < array[i - 1]) {
            my_swap(&array[i], &array[i - 1]);
            i = 1;
        }
    }
}

int main(void)
{
    int array_size = 21;
    int array[21] = {9, 6, 8, 7, 3, 1, 0, 2, 4, 5, 12, 1086, 3, 76, 137, 86, 8754, 87, 90, 46, 64};

    my_sort_int_array(array, array_size);
    for (int i = 0; i != array_size; i++) {
        my_put_nbr(array[i]);
        if (i < array_size - 1) {
            my_putchar(',');
            my_putchar(' ');
        }
        else
            my_putchar('\n');
    }
    return (0);
}