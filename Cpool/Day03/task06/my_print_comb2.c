#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}

int sub(int a, int b, int c, int d)
{
    if (a - c != 0) {
        return (a - c);
    }
    else {
        return (b - d);
    }
}

int my_print_comb2(void)
{
    char a = '0';
    char b = '0';
    char c = '0';
    char d = '0';

    for (int i = 0; a <= '9'; i++, a++) {
        for (int j = 0; b <= '9'; i++, b++){
            for (int n = 0; c <= '9'; n++, c++) {
                for (int m = 0; d <= '9'; m++, d++) {
                    if (sub(a, b, c, d) < 0) {
                        my_putchar(a);
                        my_putchar(b);
                        my_putchar(' ');
                        my_putchar(c);
                        my_putchar(d);
                        my_putchar('\n');
                    }
                }
                d = '0';
            }
            c = '0';
        }
        b = '0';
    }
    return (0);
}

int main(void)
{
    my_print_comb2();
    return (0);
}