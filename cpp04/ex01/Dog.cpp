/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 23:12:28 by mbentahi          #+#    #+#             */
/*   Updated: 2024/11/07 17:32:41 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	brain = new Brain();
	setType("Dog");
}

Dog::Dog(std::string name)
{
	setType(name);
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &c)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = c;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	if (brain)
		delete brain;
}

Dog &Dog::operator=(const Dog &c)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this == &c)
		return (*this);
	this->type = c.getType();
	this->brain = new Brain(*c.brain);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Wouf" << std::endl;
}