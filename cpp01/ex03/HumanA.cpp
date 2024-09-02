/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:02:19 by mbentahi          #+#    #+#             */
/*   Updated: 2024/08/31 15:54:20 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name,Weapon &weapon): name(name) , weapon(weapon) 
{
	
}

HumanA::~HumanA()
{
	
}

void HumanA::attack()
{
	std::cout << this->name << " attacks with his " << this->weapon.get_type() << std::endl;
}
