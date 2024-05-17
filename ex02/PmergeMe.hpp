#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <deque>
#include <vector>

class PmergeMe {
	std::vector<int> list1;
	std::deque<int> list2;
	
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &p);
		PmergeMe &operator= (const PmergeMe &p);
		~PmergeMe();

		std::vector<int> sortVector();
		std::deque<int> sortDeque();
		void addToVector(int num);
		void addToDeque(int num);
};

#endif