#include "PmergeMe.hpp"
#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

PmergeMe::PmergeMe() {
	// std::cout << "Constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &p) {
	(void) p;
	std::cout << "Copy constructor called" << std::endl;
}

PmergeMe &PmergeMe::operator = (const PmergeMe &p) {
	(void) p;
	std::cout << "Assignment called" << std::endl;
	return *this;
}

PmergeMe::~PmergeMe() {
	// std::cout << "Destructor called" << std::endl;
}

std::vector<int> PmergeMe::sortVector() {
	std::vector<int> result;
	int hold;
	bool even;

	even = (this->list1.size() % 2 == 0);
	if (this->list1.size() == 1)
		return this->list1; 

	//create a main chain of highest numbers in pairs:
	for (std::vector<int>::iterator i = this->list1.begin(); i != this->list1.end(); i += 2) {
		if (!even && i == this->list1.end() - 1)
			break;
		if (*i > *(i + 1)) {
			hold = *i;
			*i = *(i + 1);
			*(i + 1) = hold;
		}
		result.push_back(*(i + 1));
	}

	for (std::vector<int>::iterator i = this->list1.begin(); i != this->list1.end(); i++) {
		if (!even && i == this->list1.end() - 1)
			break;
		this->list1.erase(i + 1);
	}

	// sorting main chain:
	std::sort(result.begin(), result.end());

	// merging:
	while (!this->list1.empty()) {
		result.insert(std::lower_bound(result.begin(), result.end(), this->list1.back()), this->list1.back());
		this->list1.pop_back();
	}

	return result;
}

std::deque<int> PmergeMe::sortDeque() {
	std::deque<int> result;
	int hold;
	bool even;

	even = (this->list2.size() % 2 == 0);
	if (this->list2.size() == 1)
		return this->list2; 

	//create a main chain of highest numbers in pairs:
	for (std::deque<int>::iterator i = this->list2.begin(); i != this->list2.end(); i += 2) {
		if (!even && i == this->list2.end() - 1)
			break;
		if (*i > *(i + 1)) {
			hold = *i;
			*i = *(i + 1);
			*(i + 1) = hold;
		}
		result.push_back(*(i + 1));
	}

	std::sort(result.begin(), result.end());

	if (!even) {
		result.insert((std::lower_bound(result.begin(), result.end(), this->list2.back())), this->list2.back());
		this->list2.pop_back();
	}

	for (size_t i = 0; i < this->list2.size() - 1; i += 2) {
		result.insert((std::lower_bound(result.begin(), result.end(), this->list2[i])), this->list2[i]);
	}

	return result;
}

void PmergeMe::addToVector(int num) {
	this->list1.push_back(num);
}

void PmergeMe::addToDeque(int num) {
	this->list2.push_back(num);
}