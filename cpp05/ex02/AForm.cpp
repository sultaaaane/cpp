/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:08:43 by mbentahi          #+#    #+#             */
/*   Updated: 2025/02/12 17:10:49 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

Form::Form() : name("default"), issigned(false), gradeToSign(150), gradeToExec(150)
{
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : name(name), issigned(false), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &copy) : name(copy.name), issigned(copy.issigned), gradeToSign(copy.gradeToSign), gradeToExec(copy.gradeToExec)
{
	std::cout << "Form Copy Constructure" << std::endl;
	*this = copy;
}

Form &Form::operator=(Form const &copy)
{
	std::cout << "Form Assignation" << std::endl;
	if (this != &copy)
	{
		this->issigned = copy.issigned;
	}
	return *this;
}

Form::~Form()
{
	std::cout << "Form Destructure" << std::endl;
}

std::string Form::getName() const
{
	return this->name;
}

bool Form::getIsSigned() const
{
	return this->issigned;
}

int Form::getGradeToSign() const
{
	return this->gradeToSign;
}

int Form::getGradeToExec() const
{
	return this->gradeToExec;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *Form::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

std::ostream &operator<<(std::ostream &c, Form const &b)
{
	c << "Form " << b.getName() << " is signed: " << b.getIsSigned() << " grade to sign: " << b.getGradeToSign() << " grade to exec: " << b.getGradeToExec() << std::endl;
	return c;
}

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();
	this->issigned = true;
}