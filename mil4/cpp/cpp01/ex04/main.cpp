#include <string>
#include <iostream>
#include <fstream>

int	main(int ac, char **av)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		str;
	std::string		find = av[2];
	std::string		repl = av[3];
	size_t			i;
	size_t			j;

	if (ac != 4)
	{
		std::cerr << "Error\n";
		return (1);
	}
	infile.open(av[1]);
	if (!infile.good())
	{
		std::cerr << "Error\n";
		return (1);
	}
	outfile.open(std::string(av[1]).append(".replace").c_str());
	while (std::getline(infile, str))
	{
		i = 0;
		while ((j = str.find(find, i)) != str.npos)
		{
			outfile << str.substr(i, j - i);
			outfile << repl;
			i = j + find.length();
		}
		outfile << str.substr(i) + "\n";
	}
	infile.close();
	outfile.close();
}
