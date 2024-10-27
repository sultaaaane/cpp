/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:01:18 by mbentahi          #+#    #+#             */
/*   Updated: 2024/10/27 22:50:38 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap diamond("DiamondTrap");

	diamond.attack("target");
	diamond.takeDamage(10);
	diamond.beRepaired(5);
	diamond.whoAmI();

	return (0);
}