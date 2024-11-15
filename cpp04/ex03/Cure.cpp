/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:05:07 by mbentahi          #+#    #+#             */
/*   Updated: 2024/11/15 15:08:53 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	this->type = "cure";
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(std::string const &type)
{
	this->type = type;
	std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(Cure const &copy)
{
	this->type = copy.type;
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure::~Cure()
{
	t_data *new_data;

	new_data = global_data();
	if (new_data->ptr)
		ft_lstclear_free(&new_data);
	std::cout << "Cure destructor called" << std::endl;
}

Cure	&Cure::operator=(Cure const &copy)
{
	if (this == &copy)
		return (*this);
	this->type = copy.type;
	std::cout << "Cure assignation operator called" << std::endl;
	return (*this);
}

AMateria *Cure::clone() const
{
	t_data *new_data;
	
	new_data = global_data();
	std::cout << "Cure clone called" << std::endl;
	Cure *cure = new Cure();
	ft_lstadd_back_free(&new_data, init_data(cure));
	return (cure);
}

void Cure::use(ICharacter &target)
{
	(void)target;
	std::cout << "* heals " << getType() << "'s wounds *" << std::endl;
}