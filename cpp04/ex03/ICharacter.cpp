/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:29:53 by mbentahi          #+#    #+#             */
/*   Updated: 2024/11/12 19:11:57 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter()
{
	std::cout << "ICharacter default constructor called" << std::endl;
	this->count = 0;
}


ICharacter::ICharacter(ICharacter const &copy)
{
	this->name = copy.name;
	this->count = copy.count;
	for (int i = 0; i < 4; i++)
	{
		if (copy.inventory[i])
			this->inventory[i] = copy.inventory[i]->clone();
	}
	std::cout << "ICharacter copy constructor called" << std::endl;
}

ICharacter	&ICharacter::operator=(ICharacter const &copy)
{
	if (this == &copy)
		return (*this);
	this->name = copy.name;
	this->count = copy.count;
	for (int i = 0; i < 4; i++)
	{
		if (copy.inventory[i])
			this->inventory[i] = copy.inventory[i]->clone();
	}
	std::cout << "ICharacter assignation operator called" << std::endl;
	return (*this);
}

std::string const &ICharacter::getName() const
{
	return (this->name);
}

void ICharacter::equip(AMateria *m)
{
	if (this->count < 4)
	{
		this->inventory[this->count] = m;
		this->count++;
		std::cout << "Materia equiped" << std::endl;
	}
	else
		std::cout << "Inventory is full" << std::endl;
}

void ICharacter::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->inventory[idx])
	{
		this->inventory[idx] = NULL;
		this->count--;
		std::cout << "Materia unequiped" << std::endl;
	}
	else
		std::cout << "Materia not found" << std::endl;
}

void ICharacter::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && this->inventory[idx])
	{
		this->inventory[idx]->use(target);
	}
	else
		std::cout << "Materia not found" << std::endl;
}