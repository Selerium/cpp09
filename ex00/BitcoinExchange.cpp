#include "BitcoinExchange.hpp"
#include <exception>
#include <string>

BitcoinExchange::BitcoinExchange() {
	// std::cout << "Created BTC object" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &b) {
	this->database.insert(b.database.begin(), b.database.end());
	// std::cout << "Copied BTC object" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string inputFile) {
	// std::cout << "Created BTC object with inputFile: " << inputFile << std::endl;
	this->openFile();
	this->openInput(inputFile);
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &b) {
	// std::cout << "Assigned BTC object" << std::endl;
	if (this != &b) {
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {
	// std::cout << "Destroyed BTC object" << std::endl;
}

// function that stores csv values in a map container:
void BitcoinExchange::openFile() {
	std::string text;
	int day;
	int month;
	int year;
	float value;

	std::ifstream input("data.csv");
	if (!input) {
		std::cout << "Input file could not be opened" << std::endl;
		return ;
	}

	// throw out first line:
	getline(input, text);

	// getting all values:
	while (getline(input, text)) {
		try {
			if (sscanf(text.c_str(), "%d-%d-%d,%f", &year, &month, &day, &value) != 4)
				throw BitcoinExchange::InvalidInputException("Incorrect format in csv file");

			this->database.insert(std::map<int, double>::value_type((year * 10000 + month * 100 + day), value));
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}

// function that reads each line of the input file to calculate the output:
void BitcoinExchange::openInput(std::string file) {
	std::string text;
	int day;
	int month;
	int year;
	float value;

	int key;

	std::ifstream input(file.c_str());
	if (!input) {
		std::cout << "Error: coule not open file." << std::endl;
		return ;
	}

	// throw out first line:
	getline(input, text);

	// getting all values:
	while (getline(input, text)) {
		try {
			if (sscanf(text.c_str(), "%d-%d-%d | %f", &year, &month, &day, &value) != 4) {
				throw BitcoinExchange::InvalidInputException("Error: bad input => " + text);
			}

			// verifying the numbers:
			this->verifyDate(year, month, day);
			this->verifyValue(value);

			// creating unique keys using the year/month/day as keys:
			key = (year * 10000 + month * 100 + day);

			// throwing exception if there is no date less than or equal to input date:
			if (key < this->database.begin()->first)
				throw BitcoinExchange::InvalidInputException("Error: no value for such date.");

			// finding lower bound if the key is not found:
			while (this->database.find(key)->first < 20000000) {
				key = (year * 10000 + month * 100 + --day);
				if (day <= 0) {
					month -= 1;
					day = 31;
				}
				if (month <= 0) {
					year -= 1;
					month = 12;
				}
			}

			// printing multiplication of input value and csv value:
			std::cout << key / 10000 << "-"
				<< ((key % 10000) / 100 < 10 ? "0" : "") << (key % 10000) / 100 <<  "-"
				<< (key % 100 < 10 ? "0" : "") << key % 100 << " => "
				<< this->database.find(key)->second << " = "
				<< this->database.find(key)->second * value
				<< std::endl;

		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}

void BitcoinExchange::verifyDate(int year, int month, int day) {
	// invalid dates
	if (year < 0 || month < 0 || month > 12 || day > 31)
		throw BitcoinExchange::InvalidInputException("Error: invalid date.");

	// 30 vs 31 day months
	if (month < 8) {
		if (month % 2 == 0 && day > 30)
			throw BitcoinExchange::InvalidInputException("Error: invalid date.");
	}
	else {
		if (month % 2 != 0 && day > 30)
			throw BitcoinExchange::InvalidInputException("Error: invalid date.");
	}

	// february check
	if (month == 2) {
		if ((year % 100 == 0 && year % 400 == 0) || year % 4 == 0) {
			if (day > 29)
				throw BitcoinExchange::InvalidInputException("Error: invalid date.");
		}
		else {
			if (day > 28)
				throw BitcoinExchange::InvalidInputException("Error: invalid date.");
		}
	}
}

void BitcoinExchange::verifyValue(float value) {
	if (value <= 0.0)
		throw BitcoinExchange::InvalidInputException("Error: not a positive number.");
	if (value >= 1000.0)
		throw BitcoinExchange::InvalidInputException("Error: too large a number.");
}

BitcoinExchange::InvalidInputException::InvalidInputException() throw() {
}

BitcoinExchange::InvalidInputException::InvalidInputException(std::string msg) throw() : what_msg(msg.c_str()){
}

BitcoinExchange::InvalidInputException::~InvalidInputException() throw() {
}

const char *BitcoinExchange::InvalidInputException::what() const throw() {
	return what_msg.c_str();
}