/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:05:09 by mbentahi          #+#    #+#             */
/*   Updated: 2025/04/17 14:06:25 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base * generate(void)
{
	int random = rand() % 3;
	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p)
{
		if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	const std::string types[] = {"A", "B", "C"};

	for(int i = 0; i < 3; i++) {
		try
		{
			Base &result = p;
			switch(i)
			{
				case 0: result = dynamic_cast<A&>(p); break;
				case 1: result = dynamic_cast<B&>(p); break;
				case 2: result = dynamic_cast<C&>(p); break;
			}
			std::cout << types[i] << std::endl;
			return;
		}
		catch(const std::bad_cast& e)
		{
			std::cerr << e.what() << std::endl;
			continue;
		}
	}
}