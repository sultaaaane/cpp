/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:01:18 by mbentahi          #+#    #+#             */
/*   Updated: 2024/10/13 21:38:35 by mbentahi         ###   ########.fr       */
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
	clap.takeDamage(10);
	clap.beRepaired(5);
	
	scav.attack("target");
	scav.takeDamage(10);
	scav.beRepaired(5);

	frag.attack("target");
	frag.takeDamage(10);
	frag.beRepaired(5);

	return (0);
}