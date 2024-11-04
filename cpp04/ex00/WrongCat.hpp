/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:13:09 by mbentahi          #+#    #+#             */
/*   Updated: 2024/11/04 13:13:49 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"
# include <iostream>
# include <fstream>
# include <string>
# include <limits>
# include <cctype>
# include <cstdlib>
# include <iomanip>
# include <fcntl.h>

class WrongCat : public WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongCat();
		WrongCat(std::string name);
		WrongCat(const WrongCat &c);
		~WrongCat();
		WrongCat &operator=(const WrongCat &c);
		void  makeSound() const;
};