#include"RPN.hpp"

RPN::RPN() {
	// std::cout << "Constructed an RPN calculator" << std::endl;
}

RPN::RPN(const RPN &r) : numbers(r.numbers) {
	// std::cout << "Copied an RPN calculator" << std::endl;
}

RPN &RPN::operator=(const RPN &r) {
	// std::cout << "Copy assigned an RPN calculator" << std::endl;
	if (this != &r) {
		this->numbers = r.numbers;
	}
	return (*this);
}

RPN::~RPN() {
	// std::cout << "Destructed an RPN calculator" << std::endl;
}

std::stack<float> RPN::getList() {
	return this->numbers;
}

void RPN::addToNumList(char num) {
	std::string chars = "+-*/";
	std::string nums = "0123456789";
	float result;

	if (this->numbers.size() >= 2) {
		if (nums.find(num) != std::string::npos)
			this->numbers.push(static_cast<float>(num - '0'));
		else if (chars.find(num) != std::string::npos) {
			if (num == '+') {
				result = this->numbers.top();
				this->numbers.pop();
				result += this->numbers.top();
				this->numbers.pop();
				this->numbers.push(result);
			}
			else if (num == '-') {
				result = -this->numbers.top();
				this->numbers.pop();
				result += this->numbers.top();
				this->numbers.pop();
				this->numbers.push(result);
			}
			else if (num == '*') {
				result = this->numbers.top();
				this->numbers.pop();
				result *= this->numbers.top();
				this->numbers.pop();
				this->numbers.push(result);
			}
			else {
				result = 1 / this->numbers.top();
				this->numbers.pop();
				result *= this->numbers.top();
				this->numbers.pop();
				this->numbers.push(result);
			}
		}
		else
			throw RPN::RPNException("Error: invalid character");
	} else {
		this->numbers.push(static_cast<float>(num - '0'));
		if (this->numbers.top() < 0.0 || this->numbers.top() > 9.0)
			throw RPN::RPNException("Error: invalid expression");
	}
}

RPN::RPNException::RPNException() throw() {
}

RPN::RPNException::RPNException(std::string msg) throw() : what_msg(msg) {
}

RPN::RPNException::~RPNException() throw() {
}

const char* RPN::RPNException::what() const throw() {
	return what_msg.c_str();
}