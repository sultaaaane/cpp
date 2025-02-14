/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:38:00 by mbentahi          #+#    #+#             */
/*   Updated: 2025/02/14 10:45:21 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const &copy);
		Intern &operator=(Intern const &copy);
		~Intern();
		Form *makeForm(std::string name, std::string target);
		static Form *createShrubberyCreationForm(std::string target);
		static Form *createRobotomyRequestForm(std::string target);
		static Form *createPresidentialPardonForm(std::string target);
		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

};