/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:14:29 by mbentahi          #+#    #+#             */
/*   Updated: 2025/02/13 19:20:52 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	{
		Form* rrf = NULL;
		try
		{
			Bureaucrat b1("CEO", 2);
			Bureaucrat b2("Assistant", 150);
			Intern someRandomIntern;

			rrf = someRandomIntern.makeForm("robotomy", "Bender");
			rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
			if (!rrf)
				return 1;
			std::cout << *rrf << std::endl;
			rrf->beSigned(b1);
			std::cout << *rrf << std::endl;
			b1.signForm(*rrf);
			b1.executeForm(*rrf);

			b2.signForm(*rrf);
			b2.executeForm(*rrf);
			delete rrf;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			delete rrf;
		}
	}
}