/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:01:18 by mbentahi          #+#    #+#             */
/*   Updated: 2024/10/11 16:25:59 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap claptrap;
	ClapTrap claptrap2(claptrap);
	ClapTrap claptrap3 = claptrap;

	claptrap.attack("target");
	claptrap.takeDamage(5);
	claptrap.beRepaired(5);
	return (0);
}