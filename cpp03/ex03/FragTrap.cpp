/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 21:32:52 by mbentahi          #+#    #+#             */
/*   Updated: 2024/10/27 22:07:44 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	setHitpoints(100);
	setEnergyPoints(50);
	setAttackDamage(30);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	setHitpoints(100);
	setEnergyPoints(50);
	setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap &c)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = c;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &c)
{
	std::cout << "FragTrap assignation operator called" << std::endl;
	if (this == &c)
		return (*this);
	this->setName(c.getName());
	this->setHitpoints(c.getHitpoints());
	this->setEnergyPoints(c.getEnergyPoints());
	this->setAttackDamage(c.getAttackDamage());
	return (*this);
}

void FragTrap::attack(const std::string &target)
{
	if (getHitpoints() >= 1 && getEnergyPoints() >= 1)
	{
		std::cout << "FragTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
		setEnergyPoints(getEnergyPoints() - 1);
	}
	else
	{
		std::cout << "FragTrap " << getName() << " is out of energy points!" << std::endl;
	}
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << getName() << " high fives guys!" << std::endl;
}

