/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:15:57 by mbentahi          #+#    #+#             */
/*   Updated: 2024/11/04 13:18:23 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat Default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(std::string name)
{
	std::cout << "WrongCat Default constructor called" << std::endl;
	this->type = name;
}

WrongCat::WrongCat(const WrongCat &c)
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = c;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &c)
{
	std::cout << "WrongCat Assignation operator called" << std::endl;
	if (this != &c)
	{
		this->type = c.type;
		return (*this);
	}
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "Am a cat : Wooof Wooof" << std::endl;
}