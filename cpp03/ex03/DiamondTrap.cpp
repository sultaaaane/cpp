/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:28:23 by mbentahi          #+#    #+#             */
/*   Updated: 2024/10/27 22:50:11 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->name = name;
	ClapTrap::setName(name + "_clap_name");
}

DiamondTrap::DiamondTrap(const DiamondTrap &c)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = c;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &c)
{
	std::cout << "DiamondTrap assignation operator called" << std::endl;
	if (this == &c)
		return (*this);
	this->name = c.name;
	this->setHitpoints(c.getHitpoints());
	this->setEnergyPoints(c.getEnergyPoints());
	this->setAttackDamage(c.getAttackDamage());
	return (*this);
}

void DiamondTrap::attack(const std::string &target)
{
	FragTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "My name is " << name << " and my ClapTrap name is " << ClapTrap::getName() << std::endl;
}

