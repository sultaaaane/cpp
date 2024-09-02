/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:01:09 by mbentahi          #+#    #+#             */
/*   Updated: 2024/08/31 15:54:04 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

# include <iostream>
# include <string>
# include <limits>
# include <cctype>
# include <cstdlib>
# include <iomanip>

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon();
		std::string get_type();
		void setType(std::string type);
	private:
		std::string type;	
};


#endif