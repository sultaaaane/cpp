/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 23:14:29 by mbentahi          #+#    #+#             */
/*   Updated: 2024/11/15 14:39:02 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	brain = new Brain();
	setType("Cat");
}

Cat::Cat(std::string name)
{
	setType(name);
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &c)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = c;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	if (brain)
		delete brain;
}

Cat &Cat::operator=(const Cat &c)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this == &c)
		return (*this);
	this->type = c.getType();
	this->brain = new Brain(*c.brain);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Miaou" << std::endl;
}