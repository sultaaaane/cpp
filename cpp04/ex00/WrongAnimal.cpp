/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:10:57 by mbentahi          #+#    #+#             */
/*   Updated: 2024/11/04 13:12:55 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal Default constructor called" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(std::string name)
{
	std::cout << "WrongAnimal Default constructor called" << std::endl;
	this->type = name;
}

WrongAnimal::WrongAnimal(const WrongAnimal &c)
{
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	*this = c;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &c)
{
	std::cout << "WrongAnimal Assignation operator called" << std::endl;
	if (this != &c)
	{
		this->type = c.type;
		return (*this);
	}
	return (*this);
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}

void	WrongAnimal::setType(std::string type)
{
	this->type = type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makeSound called" << std::endl;
}