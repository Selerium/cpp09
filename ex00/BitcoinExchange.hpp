#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <exception>
#include<iostream>
#include <cstdio>
#include <fstream>
#include <string>
# include <map>

class BitcoinExchange {
	std::map<int, double> database;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &b);
		BitcoinExchange(std::string inputFile);
		BitcoinExchange &operator=(const BitcoinExchange &b);
		~BitcoinExchange();

		void openFile();
		void openInput(std::string file);
		void verifyDate(int year, int month, int day);
		void verifyValue(float value);

		class InvalidInputException : public std::exception {
			std::string what_msg;

			public:
				InvalidInputException() throw();
				InvalidInputException(std::string msg) throw();
				~InvalidInputException() throw();
				virtual const char* what() const throw();
		};
};

#endif