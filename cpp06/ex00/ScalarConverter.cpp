/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:08:37 by mbentahi          #+#    #+#             */
/*   Updated: 2025/04/03 11:18:54 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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

void ScalarConverter::toChar()
{

}