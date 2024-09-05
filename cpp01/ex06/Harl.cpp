/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:42:44 by mbentahi          #+#    #+#             */
/*   Updated: 2024/09/05 14:31:42 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug()
{
	std::cout << "[ DEBUG ]"<< std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "[ INFO ]"<< std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "[ WARNING ]"<< std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
	std::cout << "[ ERROR ]"<< std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG","INFO", "WARNING" ,"ERROR"};

	int i = 0;
	while (i < 4)
	{
		if (level == levels[i])
			break;
		i++;
	}
	switch (i)
	{
	case 0:
		debug();
		info();
		warning();
		error();
		break;
	case 1:
		info();
		warning();
		error();
		break;
	case 2:
		warning();
		error();
		break;
	case 3:
		error();
		break;
	default:
		std::cout << "level unknown :" << level << "." << std::endl;
		break;
	}
	
}

Harl::Harl()
{
	
}

Harl::~Harl()
{
	
}