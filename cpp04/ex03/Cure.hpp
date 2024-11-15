/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:53:24 by mbentahi          #+#    #+#             */
/*   Updated: 2024/11/11 17:38:05 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include <iostream>
# include <fstream>
# include <string>
# include <limits>
# include <cctype>
# include <cstdlib>
# include <iomanip>
# include <fcntl.h>

class Cure : public AMateria
{
	public:
		Cure();
		Cure(Cure const &copy);
		Cure &operator=(Cure const &copy);
		virtual ~Cure();
		Cure(std::string const &type);
		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif