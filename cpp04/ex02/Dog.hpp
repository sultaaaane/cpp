/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 23:11:12 by mbentahi          #+#    #+#             */
/*   Updated: 2024/11/07 17:13:54 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <fstream>
# include <string>
# include <limits>
# include <cctype>
# include <cstdlib>
# include <iomanip>
# include <fcntl.h>

class Dog : public Animal
{
	protected:
		std::string type;
		Brain *brain;
	public:
		Dog();
		Dog(std::string name);
		Dog(const Dog &c);
		virtual ~Dog();
		Dog &operator=(const Dog &c);
		void  makeSound() const;
};