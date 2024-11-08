/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 23:13:10 by mbentahi          #+#    #+#             */
/*   Updated: 2024/11/07 17:14:14 by mbentahi         ###   ########.fr       */
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

class Cat : public Animal
{
	protected:
		std::string type;
		Brain *brain;
	public:
		Cat();
		Cat(std::string name);
		Cat(const Cat &c);
		virtual ~Cat();
		Cat &operator=(const Cat &c);
		void  makeSound() const;
		
};