/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:52:00 by mbentahi          #+#    #+#             */
/*   Updated: 2024/08/29 17:44:24 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::set_name(std::string name)
{
	this->name = name;
}

Zombie::Zombie()
{
}

std::string Zombie::get_name()
{
	return (this->name);
}

void Zombie::announce()
{
	std::cout << get_name() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << get_name() << "has been destroyed"<< std::endl;
}