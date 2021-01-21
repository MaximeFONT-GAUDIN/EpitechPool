#include <unistd.h>
#include <stdio.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}

int my_print_comb(void)
{
    char a = '0';
    char b = '0';
    char c = '0';

    for (int i = 0; a <= '7'; i++, a++) {
        for (int j = 0; b <= '9'; j++, b++) {
            for (int n = 0; c <= '9'; n++, c++) {
                if ((a != b && a != c && b != c) && (a < b && b < c)) {
                    my_putchar(a);
                    my_putchar(b);
                    my_putchar(c);
                    my_putchar('\n');
                }
            }
            c = '0';
        }
        b = '0';
    }
    return (0);
}

int main(void)
{
    my_print_comb();
    return (0);
}