/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:08:37 by mbentahi          #+#    #+#             */
/*   Updated: 2025/03/09 01:10:13 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(std::string scalar) : scalar(scalar)
{
	std::cout << "Constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &o) : scalar(o.scalar)
{
	std::cout << "Copy constructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &o)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &o)
	{
		this->scalar = o.scalar;
	}
	return (*this);
}


ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called" << std::endl;
}

