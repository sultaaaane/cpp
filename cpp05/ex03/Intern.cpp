/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:38:09 by mbentahi          #+#    #+#             */
/*   Updated: 2025/02/14 10:47:33 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &copy)
{
	*this = copy;
}

Intern &Intern::operator=(Intern const &copy)
{
	(void)copy;
	return *this;
}

Intern::~Intern()
{
}

Form *Intern::createShrubberyCreationForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

Form *Intern::createRobotomyRequestForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

Form *Intern::createPresidentialPardonForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return "Form not found";
}



Form *Intern::makeForm(std::string name, std::string target)
{
	Form* (*forms[])(std::string target) = {&Intern::createShrubberyCreationForm, &Intern::createRobotomyRequestForm, &Intern::createPresidentialPardonForm};
	std::string names[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	
	for (int i = 0; i < 3; i++)
	{
		if (name == names[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return forms[i](target);
		}
	}
	throw Intern::FormNotFoundException();
}