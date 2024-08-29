/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:51:58 by mbentahi          #+#    #+#             */
/*   Updated: 2024/08/29 17:28:21 by mbentahi         ###   ########.fr       */
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
		void announce(void);
		Zombie(std:: string name);
		~Zombie();
	private:
		std::string name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif