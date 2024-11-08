/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 23:06:38 by mbentahi          #+#    #+#             */
/*   Updated: 2024/11/07 22:37:29 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <fstream>
# include <string>
# include <limits>
# include <cctype>
# include <cstdlib>
# include <iomanip>
# include <fcntl.h>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string name);
		Animal(const Animal &c);
		virtual ~Animal();
		Animal &operator=(const Animal &c);
		std::string getType() const;
		void setType(std::string type);
		virtual void  makeSound() const = 0;
};