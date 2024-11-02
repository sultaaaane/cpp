/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:19:34 by mbentahi          #+#    #+#             */
/*   Updated: 2024/11/02 15:55:50 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	setHitpoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	setHitpoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &c)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = c;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &c)
{
	std::cout << "ScavTrap assignation operator called" << std::endl;
	if (this == &c)
		return (*this);
	this->setName(c.getName());
	this->setHitpoints(c.getHitpoints());
	this->setEnergyPoints(c.getEnergyPoints());
	this->setAttackDamage(c.getAttackDamage());
	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	if (getHitpoints() >= 1 && getEnergyPoints() >= 1)
	{
		std::cout << "ScavTrap " << getName() << " attacks " << target << " , causing " << getAttackDamage() << " points of damage!" << std::endl;
		setEnergyPoints(getEnergyPoints() - 1);
	}
	else
	{
		std::cout << "ScavTrap " << getName() << " is out of energy points!" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << getName() << " has entered in Gate keeper mode!" << std::endl;
}

