#include <unistd.h>

void putnbr(int n)
{
	char c;
	if (n > 9)
	{
		putnbr(n / 10);
		putnbr(n % 10);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

int	main(void)
{
	int i = 1;
	while (i <= 100)
	{
		if (!(i % 3 && i % 5))
		{
			if (!(i % 3))
				write(1, "fizz", 4);
			if (!(i % 5))
				write(1, "buzz",4);
		}
		else
			putnbr(i);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}