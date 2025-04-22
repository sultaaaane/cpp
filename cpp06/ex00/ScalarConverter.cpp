/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:08:37 by mbentahi          #+#    #+#             */
/*   Updated: 2025/04/22 14:47:15 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool isCharLiteral(const std::string &str)
{
	return str.length() == 3 && str[0] == '\'' && str[2] == '\'';
}

bool isFloatLiteral(const std::string &str)
{
	return str.find('f') != std::string::npos && str != "+inff" && str != "-inff" && str != "nanf";
}

bool isDoublePseudoLiteral(const std::string &str)
{
	return str == "nan" || str == "+inf" || str == "-inf";
}

bool isFloatPseudoLiteral(const std::string &str)
{
	return str == "nanf" || str == "+inff" || str == "-inff";
}
bool isIntLiteral(const std::string &str)
{
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		if (!isdigit(*it) && *it != '-' && *it != '+')
			return false;
	}
	return !str.empty() && (isdigit(str[0]) || str[0] == '-' || str[0] == '+');
}

ScalarConverter::ScalarConverter(std::string scalar) : scalar(scalar)
{
	std::cout << "Constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &o)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = o;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &o)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &o)
	{
		this->scalar = o.scalar;
		this->i = o.i;
		this->d = o.d;
		this->f = o.f;
		this->c = o.c;
	}
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called" << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
	char c;
	int i;
	float f;
	double d;

	std::cout << std::fixed << std::setprecision(1);

	if (isCharLiteral(literal))
	{
		c = literal[1];
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
	}
	else if (isFloatPseudoLiteral(literal))
	{
		c = 0;
		i = 0;
		if (literal == "+inff")
			f = std::numeric_limits<float>::infinity();
		else if (literal == "-inff")
			f = -std::numeric_limits<float>::infinity();
		else
			f = std::numeric_limits<float>::quiet_NaN();

		d = static_cast<double>(f);
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
		return;
	}
	else if (isDoublePseudoLiteral(literal))
	{
		c = 0;
		i = 0;
		if (literal == "+inf")
			d = std::numeric_limits<double>::infinity();
		else if (literal == "-inf")
			d = -std::numeric_limits<double>::infinity();
		else
			d = std::numeric_limits<double>::quiet_NaN();
		f = static_cast<float>(d);
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
		return;
	}
	else if (isFloatLiteral(literal))
	{
		try
		{
			f = atof(literal.c_str());
			d = static_cast<double>(f);
			i = static_cast<int>(f);
			c = static_cast<char>(i);
		}
		catch (...)
		{
			std::cout << "Conversion error" << std::endl;
			return;
		}
	}
	else if (literal.find('.') != std::string::npos)
	{
		try
		{
			d = atof(literal.c_str());
			f = static_cast<float>(d);
			i = static_cast<int>(d);
			c = static_cast<char>(i);
		}
		catch (...)
		{
			std::cout << "Conversion error" << std::endl;
			return;
		}
	}
	else if (isIntLiteral(literal))
	{
		try
		{
			i = atoi(literal.c_str());
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
		}
		catch (...)
		{
			std::cout << "Conversion error" << std::endl;
			return;
		}
	}
	else
	{
		std::cout << "Invalid literal format" << std::endl;
		return;
	}
	if (i < 0 || i > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;

	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}
