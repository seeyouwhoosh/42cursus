
#include "philo.h"

static int	ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int	index;
	int	number;
	int	sign;

	index = 0;
	number = 0;
	sign = 1;
	while (ft_isspace(str[index]))
		index++;
	if (str[index] == '-')
	{
		sign = -1;
		index++;
	}
	else if (str[index] == '+')
	{
		index++;
	}
	while (ft_isdigit(str[index]))
	{
		number = number * 10 + (str[index] - '0');
		index++;
	}
	return (number * sign);
}

unsigned int	gettime_milisec(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		write(2, "Error: gettimeofday()\n", 22);
		return (-1);
	}
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
