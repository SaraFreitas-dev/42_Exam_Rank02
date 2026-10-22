#include <unistd.h>

void	ft_putstr(char *str);

/* Only write() here: mixing printf would reorder the output. */
static void	test(char *s)
{
	write(1, "[", 1);
	ft_putstr(s);
	write(1, "]\n", 2);
}

int	main(void)
{
	test("Hello, 42!");
	test("");
	test("a");
	test("  spaces and\ttabs  ");
	test("line\nbreak");
	test("0123456789 !@#$%^&*()");
	return (0);
}
