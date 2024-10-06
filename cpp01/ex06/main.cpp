/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:42:26 by mbentahi          #+#    #+#             */
/*   Updated: 2024/09/08 12:12:37 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac,char **av)
{
	Harl harl;
	(void)ac;
	if (!av[1])
	{
		std::cout << "[ Probably complaining about insignificant problems ]"  << std::endl;
		return 0;
	}
	std::string level = av[1];
	harl.complain(level);
}