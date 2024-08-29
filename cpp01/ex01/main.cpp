/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:52:08 by mbentahi          #+#    #+#             */
/*   Updated: 2024/08/29 18:08:04 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int i = 0;
	int n = 0;
	Zombie *z1 = zombieHorde(n,"su");
	while (i < n)
	{
		z1[i].announce();
		i++;
	}
	if (n <= 0 || !z1)
		return 0;
	delete[] z1;
}