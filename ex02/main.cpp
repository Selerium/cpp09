#include "PmergeMe.hpp"
#include <cstdlib>
#include <deque>
#include <vector>
#include <iostream>

int main(int ac, char **av) {
	std::vector<int> result1;
	std::deque<int> result2;
	PmergeMe p;

	if (ac == 1) {
		std::cout << "Error";
		return 1;
	}

	for (int i = 1; i < ac; i++) {
		if (atoi(av[i]) < 0) {
			std::cout << "Error" << std::endl;
			return 1;
		}
		p.addToVector(atoi(av[i]));
		p.addToDeque(atoi(av[i]));
	}

	clock_t start, end;
	start = clock();
	result1 = p.sortVector();
	end = clock();
	double time1 = static_cast<double>(end - start);

	start = clock();
	result2 = p.sortDeque();
	end = clock();
	double time2 = static_cast<double>(end - start);

	std::cout << "Before:	";
	for (int i = 1; i < ac; i++) {
		std::cout << av[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "After:	";
	for (std::deque<int>::iterator i = result2.begin(); i != result2.end(); i++) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << time1 << "us" << std::endl;
	std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << time2 << "us" << std::endl;
}