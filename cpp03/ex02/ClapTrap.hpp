/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:02:02 by mbentahi          #+#    #+#             */
/*   Updated: 2024/10/13 14:25:03 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <limits>
# include <cctype>
# include <cstdlib>
# include <iomanip>
# include <fcntl.h>

class ClapTrap
{
	private:
		std::string name;
		int hitpoints;
		int energy_points;
		int attack_damage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &c);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap &c);
		void attack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void setName(std::string name);
		void setHitpoints(int hitpoints);
		void setEnergyPoints(int energy_points);
		void setAttackDamage(int attack_damage);
		std::string getName() const;
		int getHitpoints() const;
		int getEnergyPoints() const;
		int getAttackDamage() const; 
};

#endif