/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:15:08 by mbentahi          #+#    #+#             */
/*   Updated: 2025/04/17 16:27:34 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
	std::cout << "Default Bureaucrat Constructure" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructure" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
	std::cout << "Bureaucrat Constructure" << std::endl;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
	std::cout << "Bureaucrat Copy Constructure" << std::endl;
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &copy)
{
	std::cout << "Bureaucrat Assignation" << std::endl;
	if (this != &copy)
	{
		this->grade = copy.grade;
	}
	return *this;
}


void Bureaucrat::setGrade(int grade)
{
	this->grade = grade;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

std::ostream &operator<<(std::ostream &c, Bureaucrat const &b)
{
	c << b.getName() << " , bureaucrat grade " << b.getGrade() << "." << std::endl;
	return c;
}

void Bureaucrat::inc()
{
	if (getGrade() == 1)
		throw Bureaucrat::GradeTooHighException();
	else 
		setGrade(this->grade - 1);
}

void Bureaucrat::dec()
{
	if (getGrade() == 150)
		throw Bureaucrat::GradeTooLowException();
	else 
		setGrade(this->grade + 1);
}

void Bureaucrat::signForm(Form &form)
{
	if (form.getGradeToSign() < this->grade)
	{
		std::cout << this->name << " cannot sign " << form.getName() << " because his grade is too low" << std::endl;
	}
	else
	{
		std::cout << this->name << " signs " << form.getName() << std::endl;
	}
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "You can't set this grade it's too high\n";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "You can't set this grade it's too low\n";
}