#include <limits.h>
#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);

/* Only write() here: mixing printf would reorder the output. */
static void	put(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

static void	test(int nbr, char *label, char *base)
{
	put(label);
	put(" [base \"");
	put(base);
	put("\"] -> [");
	ft_putnbr_base(nbr, base);
	put("]\n");
}

int	main(void)
{
	test(42, "42", "0123456789");
	test(42, "42", "01");
	test(255, "255", "0123456789ABCDEF");
	test(-255, "-255", "0123456789abcdef");
	test(0, "0", "01");
	test(8, "8", "poneyvif");
	test(INT_MAX, "INT_MAX", "0123456789ABCDEF");
	test(INT_MIN, "INT_MIN", "0123456789");
	test(INT_MIN, "INT_MIN", "01");
	test(42, "42", "");
	test(42, "42", "0");
	test(42, "42", "0120");
	test(42, "42", "01+");
	test(42, "42", "-01");
	return (0);
}
