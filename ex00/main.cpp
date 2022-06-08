#include "TypeTreater.hpp"
#include "utils.hpp"

int	main( int argc, char **argv )
{
	TypeTreater TypeTreater;
	try
	{
		if (argc == 1)
			throw (TypeTreater::EmptyArg());
		for (int i = 1; i < argc; i++)
		{
			TypeTreater.argAnalyse(argv[i]);
			TypeTreater.printTypes();
			if (i + 1 < argc)
				std::cout << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		print_help();
	}
}
