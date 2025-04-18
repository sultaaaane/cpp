/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:14:29 by mbentahi          #+#    #+#             */
/*   Updated: 2025/04/17 17:33:52 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	{
		Form *s1 = NULL;
		Form *s2 = NULL;
		Form *s3 = NULL;
		try
		{
			Bureaucrat b1("b1", 1);
			Bureaucrat b2("b2", 100);
			s1 = new ShrubberyCreationForm("bgb");
			s2 = new RobotomyRequestForm("bgb");
			s3 = new PresidentialPardonForm("bgb");
			
			std::cout << b1;
			std::cout << b2;
			std::cout << *s1;
			std::cout << *s2;
			std::cout << *s3;

			s1->beSigned(b1);
			s2->beSigned(b1);
			s3->beSigned(b1);
			b1.signForm(*s1);
			b1.executeForm(*s1);
			b1.signForm(*s2);
			b1.executeForm(*s2);
			b1.signForm(*s3);
			b1.executeForm(*s3);
			
			delete s1;
			delete s2;
			delete s3;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
			delete s1;
			delete s2;
			delete s3;
		}
	}
}