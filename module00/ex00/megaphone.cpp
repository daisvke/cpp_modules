#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			while (*argv[i])
			{
				if (*argv[i] >= 'a' && *argv[i] <= 'z')
				{
					char	c = *argv[i] - 32;
					std::cout << c;
				}
				else if (*argv[i] != '"')
					std::cout << *argv[i];
				++argv[i];
			}
		}
	}
	std::cout << std::endl;
	return (0);
}
