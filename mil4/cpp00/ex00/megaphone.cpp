#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
	size_t	i;
	size_t	j;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	j = 0;
	while (av[++j])
	{
		i = -1;
		while (av[j][++i])
		{
			if (islower(av[j][i]))
				std::cout << (char)std::toupper(av[j][i]);
			else
				std::cout << av[j][i];
		}
	}
	std::cout << std::endl;
	return (0);
}
