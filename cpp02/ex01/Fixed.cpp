/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:25:43 by mbentahi          #+#    #+#             */
/*   Updated: 2024/10/07 21:30:03 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	value = 0;
	std::cout << "Default constructor has been called" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "copy constructor has been called" << std::endl;
	*this = f;
}

Fixed::~Fixed()
{
	std::cout << "Default deconstructor has been called" << std::endl;
}

Fixed::Fixed(int const value)
{
	std::cout << "Int constructor has been called" << std::endl;
	this->value = value << bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor has been called" << std::endl;
	this->value = roundf(value * (1 << bits));
}

Fixed &Fixed::operator=(const Fixed &f)
{
	if (this != &f)
	{
		std::cout << "copy assignment operator has been called" << std::endl;
		this->setRawBits(f.value);
		return *this;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &out, Fixed const &f)
{
	out << f.toFloat();
	return out;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
}

float Fixed::toFloat() const
{
	return ((float)value / (1 << bits));
}

int Fixed::toInt() const
{
	return (value >> bits);
}
