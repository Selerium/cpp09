#ifndef RPN_HPP
# define RPN_HPP

#include <exception>
#include <stack>
#include <string>

class RPN {
	std::stack<float> numbers;

	public:
		RPN();
		RPN(const RPN &r);
		RPN &operator=(const RPN &r);
		~RPN();

	void addToNumList(char num);
	std::stack<float> getList();

	class RPNException : public std::exception {
		std::string what_msg;

		public:
			RPNException() throw();
			RPNException(std::string msg) throw();
			~RPNException() throw();
			const virtual char* what() const throw();
	};
};

#endif