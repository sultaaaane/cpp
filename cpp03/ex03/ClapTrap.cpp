/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:01:43 by mbentahi          #+#    #+#             */
/*   Updated: 2024/11/02 15:56:26 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hitpoints(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &c)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = c;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &c)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
	if (this == &c)
		return (*this);
	this->name = c.name;
	this->hitpoints = c.hitpoints;
	this->energy_points = c.energy_points;
	this->attack_damage = c.attack_damage;
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (hitpoints >= 1 && energy_points >= 1)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << " , causing " << attack_damage << " points of damage!" << std::endl;
		energy_points--;
	}
	else
	{
		std::cout << "ClapTrap " << name << " is out of energy points!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitpoints >= 1)
	{
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
		hitpoints -= amount;
	}
	else
	{
		std::cout << "ClapTrap " << name << " is already dead!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitpoints <= 0)
	{
		std::cout << "ClapTrap " << name << " is already dead!" << std::endl;
		return ;
	}
	if (energy_points <= 0)
	{
		std::cout << "ClapTrap " << name << " is out of energy points!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " has been repaired for " << amount << " points of damage!" << std::endl;
	hitpoints += amount;
	energy_points--;
}

void ClapTrap::setName(std::string name)
{
	this->name = name;
}

void ClapTrap::setHitpoints(int hitpoints)
{
	this->hitpoints = hitpoints;
}

void ClapTrap::setEnergyPoints(int energy_points)
{
	this->energy_points = energy_points;
}

void ClapTrap::setAttackDamage(int attack_damage)
{
	this->attack_damage = attack_damage;
}

std::string ClapTrap::getName() const
{
	return (name);
}

int ClapTrap::getHitpoints() const
{
	return (hitpoints);
}

int ClapTrap::getEnergyPoints() const
{
	return (energy_points);
}

int ClapTrap::getAttackDamage() const
{
	return (attack_damage);
}
