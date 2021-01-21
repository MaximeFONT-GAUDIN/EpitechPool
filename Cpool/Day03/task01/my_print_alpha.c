#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}

int my_print_alpha(void)
{
	for (int i = 'a'; i != ('z' + 1); i++)
		my_putchar(i);
	return (0);
}

int main(void)
{
	my_print_alpha();
	return (0);
}
