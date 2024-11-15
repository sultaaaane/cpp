/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:23:25 by mbentahi          #+#    #+#             */
/*   Updated: 2024/11/15 14:46:46 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "free.hpp"
# include "ICharacter.hpp"
# include <iostream>
# include <fstream>
# include <string>
# include <limits>
# include <cctype>
# include <cstdlib>
# include <iomanip>
# include <fcntl.h>

class ICharacter;
class AMateria
{
	protected:
		std::string type;
	public: 
		AMateria();
		AMateria(AMateria const &copy);
		AMateria &operator=(AMateria const &copy);
		virtual ~AMateria();
		AMateria(std::string const &type);
		std::string const &getType() const; // Returns the materia type
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);
};

#endif