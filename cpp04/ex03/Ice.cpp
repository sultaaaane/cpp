/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:04:04 by mbentahi          #+#    #+#             */
/*   Updated: 2024/11/15 14:52:33 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	this->type = "ice";
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(std::string const &type)
{
	this->type = type;
	std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(Ice const &copy)
{
	this->type = copy.type;
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice::~Ice()
{
	t_data *new_data;

	new_data = global_data();
	if (new_data->ptr)
		ft_lstclear_free(&new_data);
	std::cout << "Ice destructor called" << std::endl;
}

Ice	&Ice::operator=(Ice const &copy)
{
	if (this == &copy)
		return (*this);
	this->type = copy.type;
	std::cout << "Ice assignation operator called" << std::endl;
	return (*this);
}

AMateria *Ice::clone() const
{
	t_data *new_data;

	new_data = global_data();
	std::cout << "Ice clone called" << std::endl;
	Ice *ice = new Ice();
	ft_lstadd_back_free(&new_data, init_data(ice));
	return (ice);
}

void Ice::use(ICharacter &target)
{
	(void)target;
	std::cout << "* shoots an ice bolt at " << getType() << " *" << std::endl;
}
