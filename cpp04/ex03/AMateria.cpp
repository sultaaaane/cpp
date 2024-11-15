/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:23:23 by mbentahi          #+#    #+#             */
/*   Updated: 2024/11/10 16:03:11 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	this->type = "default";
	std::cout << "Amateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
	std::cout << "Amateria constructor called" << std::endl;
}

AMateria::AMateria(AMateria const &copy)
{
	this->type = copy.type;
	std::cout << "Amateria copy constructor called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "Amateria destructor called" << std::endl;
}

AMateria	&AMateria::operator=(AMateria const &copy)
{
	if (this == &copy)
		return (*this);
	this->type = copy.type;
	std::cout << "Amateria assignation operator called" << std::endl;
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter &target)
{
	(void)target;
	std::cout << "Amateria use called" << std::endl;
}