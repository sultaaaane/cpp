/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:01:18 by mbentahi          #+#    #+#             */
/*   Updated: 2024/11/02 15:14:23 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap clap("ClapTrap");
	ScavTrap scav("ScavTrap");
	FragTrap frag("FragTrap");

	clap.attack("target");
	clap.takeDamage(5);
	clap.beRepaired(5);
	clap.setName("ClapTrap");
	clap.setHitpoints(10);
	clap.setEnergyPoints(10);
	clap.setAttackDamage(5);
	std::cout << clap.getName() << std::endl;
	std::cout << clap.getHitpoints() << std::endl;
	std::cout << clap.getEnergyPoints() << std::endl;
	std::cout << clap.getAttackDamage() << std::endl;


	scav.attack("target");
	scav.takeDamage(5);
	scav.beRepaired(5);
	scav.setName("ScavTrap");
	scav.setHitpoints(10);
	scav.setEnergyPoints(10);
	scav.setAttackDamage(5);
	std::cout << scav.getName() << std::endl;
	std::cout << scav.getHitpoints() << std::endl;
	std::cout << scav.getEnergyPoints() << std::endl;
	std::cout << scav.getAttackDamage() << std::endl;
	scav.guardGate();

	frag.attack("target");
	frag.takeDamage(5);
	frag.beRepaired(5);
	frag.setName("FragTrap");
	frag.setHitpoints(10);
	frag.setEnergyPoints(10);
	frag.setAttackDamage(5);
	std::cout << frag.getName() << std::endl;
	std::cout << frag.getHitpoints() << std::endl;
	std::cout << frag.getEnergyPoints() << std::endl;
	std::cout << frag.getAttackDamage() << std::endl;
	frag.highFivesGuys();
	
	return (0);
}