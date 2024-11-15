/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:20:02 by mbentahi          #+#    #+#             */
/*   Updated: 2024/11/15 15:10:14 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	std::cout << "Character default constructor called" << std::endl;
	this->count = 0;
}

Character::Character(std::string const &name)
{
	this->name = name;
	std::cout << "Character constructor called" << std::endl;
}

Character::Character(Character const &copy)
{
	t_data *new_data;

	new_data = global_data();
	this->name = copy.name;
	this->count = copy.count;
	for (int i = 0; i < 4; i++)
	{
		if (copy.inventory[i])
		{
			this->inventory[i] = copy.inventory[i]->clone();
			ft_lstadd_back_free(&new_data, init_data(this->inventory[i]));
		}
	}
	std::cout << "Character copy constructor called" << std::endl;
}

Character::~Character()
{
	// for (int i = 0; i < 4; i++)
	// {
	// 	if (this->inventory[i] && count > 0)
	// 		delete this->inventory[i];
	// }
	t_data *new_data;

	new_data = global_data();
	if (new_data->ptr)
		ft_lstclear_free(&new_data);
	std::cout << "Character destructor called" << std::endl;
}

Character	&Character::operator=(Character const &copy)
{
	if (this == &copy)
		return (*this);
	this->name = copy.name;
	this->count = copy.count;
	for (int i = 0; i < 4; i++)
	{
		if (copy.inventory[i])
			this->inventory[i] = copy.inventory[i]->clone();
	}
	std::cout << "Character assignation operator called" << std::endl;
	return (*this);
}

std::string const &Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria *m)
{
	if (this->count < 4)
	{
		this->inventory[this->count] = m;
		this->count++;
		std::cout << "Materia equiped" << std::endl;
	}
	else
		std::cout << "Inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->inventory[idx])
	{
		this->inventory[idx] = NULL;
		std::cout << "Materia unequiped" << std::endl;
	}
	else
		std::cout << "Materia not found" << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && this->inventory[idx])
	{
		this->inventory[idx]->use(target);
		std::cout << "Materia used" << std::endl;
	}
	else
		std::cout << "Materia not found" << std::endl;
}