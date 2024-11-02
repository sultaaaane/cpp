/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:02:02 by mbentahi          #+#    #+#             */
/*   Updated: 2024/11/02 16:06:12 by mbentahi         ###   ########.fr       */
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
	protected:
		std::string name;
		int hitpoints;
		int energy_points;
		int attack_damage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &c);
		virtual ~ClapTrap();
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