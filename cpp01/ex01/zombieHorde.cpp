/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:52:02 by mbentahi          #+#    #+#             */
/*   Updated: 2024/08/29 18:08:23 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	int i = 0;
	
	if (N <= 0)
		return NULL;
	Zombie *horde = new Zombie[N];
	while (i < N)
	{
		horde[i].set_name(name);
		i++;
	}
	return horde;
}
