/* **************************************************************************************************************** */
/*				                                    ⠤⣤⣤⣤⣄⣀⣀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣠⣤⠤⠤⠴⠶⠶⠶⠶	 */
/*				                                    ⢠⣤⣤⡄⣤⣤⣤⠄⣀⠉⣉⣙⠒⠤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠴⠘⣉⢡⣤⡤⠐⣶⡆⢶⠀⣶⣶⡦	 */
/*	RPN.cpp                       	                ⣄⢻⣿⣧⠻⠇⠋⠀⠋⠀⢘⣿⢳⣦⣌⠳⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠞⣡⣴⣧⠻⣄⢸⣿⣿⡟⢁⡻⣸⣿⡿⠁   */
/*	                                                 ⠃⠙⢿⣧⣙⠶⣿⣿⡷⢘⣡⣿⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣷⣝⡳⠶⠶⠾⣛⣵⡿⠋⠀    */
/*													     ⠉⠻⣿⣶⠂⠘⠛⠛⠛⢛⡛⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠛⠀⠉⠒⠛⠀⠀⠀⠀    */
/*	By: mbentahi <Mohamadalaoui77@gmail.com>               ⣿⡇⠀⠀⠀⠀⠀⢸⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀	⠀ */
/*	                 								⠀⠀⠀⠀⠀ ⣿⡇⠀⠀⠀⠀⠀⣾⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀	 */
/*	Created: 4/30/2025, 10:16:55 AM        		⠀⠀⠀ ⠀⠀⠀  ⣿⡇⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  */
/*	Updated: 5/4/2025, 3:44:43 PM          		⠀⠀⠀ ⠀⠀⠀  ⢻⡁⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  */
/*													⠀⠀⠀⠀⠀⠘⡇                                                       */
/*													⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀	 */
/*                                                         ⠿                                                        */
/* **************************************************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const &c)
{
	*this = c;
}

RPN &RPN::operator=(RPN const &c)
{
	if (this != &c)
	{
		this->stack = c.stack;
	}
	return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string &token) const
{
	return token == "+" || token == "-" || token == "*" || token == "/";
}

void RPN::performOperation(const std::string &op)
{
	if (stack.size() < 2)
	{
		throw std::runtime_error("Error: not enough operands for operation");
	}

	int b = stack.top();
	stack.pop();
	int a = stack.top();
	stack.pop();

	if (op == "+")
		stack.push(a + b);
	else if (op == "-")
		stack.push(a - b);
	else if (op == "*")
		stack.push(a * b);
	else if (op == "/")
	{
		if (b == 0)
			throw std::runtime_error("Error: division by zero");
		stack.push(a / b);
	}
}

void RPN::calculate(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (isOperator(token))
			performOperation(token);
		else
		{
			char *end;
			long num = std::strtol(token.c_str(), &end, 10);
			if (*end != '\0')
				throw std::runtime_error("Error: invalid");
			if (num < 0 || num > 9)
				throw std::runtime_error("Error: numbers must be between 0 and 9");
			stack.push(static_cast<int>(num));
		}
	}

	if (stack.size() != 1)
		throw std::runtime_error("Error: invalid expression");
	std::cout << stack.top() << std::endl;
}