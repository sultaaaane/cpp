/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:14:29 by mbentahi          #+#    #+#             */
/*   Updated: 2025/02/13 16:58:06 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	{
		Form *s1 = NULL;
		try
		{
			Bureaucrat b1("b1", 1);
			Bureaucrat b2("b2", 150);
			s1 = new RobotomyRequestForm("bgb");

			std::cout << b1;
			std::cout << b2;
			std::cout << *s1;

			s1->beSigned(b1);
			b1.signForm(*s1);
			b1.executeForm(*s1);

			std::cout << std::endl;

			// s1->beSigned(b2);
			b2.signForm(*s1);
			b2.executeForm(*s1);
			delete s1;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			delete s1;
		}
	}
}