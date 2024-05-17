#include"BitcoinExchange.hpp"

int main (int argc, char **argv) {
	(void) argc;
	(void) argv;

	if (argc != 2) {
		std::cout << "Error: wrong number of arguments." << std::endl;
		return 1;
	}
	BitcoinExchange obj(argv[1]);
	return 0;
}