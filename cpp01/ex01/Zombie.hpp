/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:51:58 by mbentahi          #+#    #+#             */
/*   Updated: 2024/08/29 17:44:12 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <limits>
# include <cctype>
# include <cstdlib>
# include <iomanip>

class Zombie
{
	public:
		std::string get_name();
		void set_name(std::string name);
		void announce(void);
		Zombie();
		~Zombie();
	private:
		std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif