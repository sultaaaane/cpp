/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 23:07:42 by mbentahi          #+#    #+#             */
/*   Updated: 2024/10/29 18:43:08 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string name)
{
	setType(name);
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &c)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = c;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &c)
{
	std::cout << "Animal assignation operator called" << std::endl;
	if (this == &c)
		return (*this);
	this->type = c.getType();
	return (*this);
}

std::string Animal::getType() const
{
	return (type);
}

void Animal::setType(std::string type)
{
	this->type = type;
}

void Animal::makeSound() const
{
	std::cout << "Animal sound !!" << std::endl;
}