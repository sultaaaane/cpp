/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:53:05 by mbentahi          #+#    #+#             */
/*   Updated: 2024/11/11 17:37:55 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include <iostream>
# include <fstream>
# include <string>
# include <limits>
# include <cctype>
# include <cstdlib>
# include <iomanip>
# include <fcntl.h>

class Ice : public AMateria
{
	public:
		Ice();
		Ice(Ice const &copy);
		Ice &operator=(Ice const &copy);
		virtual ~Ice();
		Ice(std::string const &type);
		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif