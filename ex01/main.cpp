#include <string>
#include <iostream>
#include "RPN.hpp"

int main (int argc, char **argv) {
	RPN calculator;
	int nums = 0, ops = 0;
	std::string c;
	std::string numbers = "01234567890";
	std::string operators = "+-*/";

	if (argc == 1)
		std::cout << "Error: not enough arguments" << std::endl;

	if (argc == 2) {
		c = argv[1];
		for (size_t i = 0; i < c.length(); i++) {
			if (i % 2 == 0) {
				if (numbers.find(c[i]) != std::string::npos)
					calculator.addToNumList(c[i]);
				else if (operators.find(c[i]) != std::string::npos)
					calculator.addToNumList(c[i]);
				else {
					std::cout << "Error: incorrect input" << std::endl;
					return 1;
				}
			} else {
				if (c[i] != ' ') {
					std::cout << "Error: incorrect input" << std::endl;
					return 1;
				}
			}
		}
		for (size_t i = 0; i < c.length(); i++) {
			if (i % 2 == 0) {
				if (numbers.find(c[i]) != std::string::npos)
					nums++;
				else if (operators.find(c[i]) != std::string::npos)
					ops++;
			}
		}
		if (nums != ops + 1) {
			std::cout << "Error: incorrect expression" << std::endl;
			return 1;
		}
		std::cout << calculator.getList().top() << std::endl;
	}
}